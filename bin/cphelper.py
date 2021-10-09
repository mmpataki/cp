import os, sys, shutil, subprocess, time, json, requests, datetime, html, random
from urllib.request import Request, urlopen
from urllib.parse import unquote
from bs4 import BeautifulSoup
from itertools import zip_longest

class Colors:
	HEADER = '\033[95m'
	OKBLUE = '\033[94m'
	OKGREEN = '\033[92m'
	WARNING = '\033[93m'
	FAIL = '\033[91m'
	ENDC = '\033[0m'
	BOLD = "\033[1m"
	DIM = "\033[2m"
	ITALIC = "\033[3m"
	TITLE_FRONT = "\033[1;4m"
	TITLE_BCK = ""

def doPrint(x, color=""):
	print(color + x + Colors.ENDC)
def info(x):
	doPrint(x.rstrip())
def err(x):
	doPrint(x.rstrip(), Colors.FAIL + Colors.BOLD)
def title(x):
	doPrint(x.rstrip(), Colors.TITLE_BCK + Colors.TITLE_FRONT + Colors.BOLD)
def warn(x):
	doPrint(x.rstrip(), Colors.WARNING + Colors.BOLD)
def label(x):
	doPrint(x.rstrip(), Colors.OKBLUE + Colors.BOLD + Colors.ITALIC)
def status(msg, res_and_msg, extra=""):
	colors=[Colors.FAIL, Colors.OKGREEN, Colors.WARNING]
	stdmsgs=["FAILED", "SUCCESS"]
	color,tok=(colors[res_and_msg[0]],res_and_msg[1]) if type(res_and_msg) is tuple else (colors[res_and_msg], stdmsgs[res_and_msg])
	doPrint(Colors.BOLD + msg + color + tok + Colors.HEADER + " " + extra + Colors.ENDC)

def doGet(url):
	info(f'http: {url}')
	return urlopen(Request(url, None, {'User-Agent' : 'Mozilla/5.0 (Linux; U; Android 4.4.2; en-us; SCH-I535 Build/KOT49H)'}))

class Problem():
	def __init__(self, id, name, time=0, memory=0):
		self.id, self.name, self.time, self.memory, self.tests = id, name, time, memory, []

	def addTest(self, inp, out):
		self.tests.append([str(inp).strip(), str(out).strip()])

	def setup(self, baseDir, lang):
		ppath = baseDir + "/" + self.id
		try: os.makedirs(ppath)
		except: return

		# copy the template
		self.solfile = f"{ppath}/{self.id}.{lang}"
		shutil.copyfile(f"{baseDir}/../../template.{lang}", self.solfile)

		# copy the input and output files
		i = 0
		for test in self.tests:
			fp=open(f"{ppath}/in.{i}.txt", "w")
			fp.write(test[0])
			fp.close()
			fp=open(f"{ppath}/out.{i}.txt", "w")
			fp.write(test[1])
			fp.close()
			i+=1

class Contest():
	def __init__(self, id, name, html=""):
		self.id , self.name, self.problems, self.html = id, name, [], html

	def addProblem(self, problem):
		self.problems.append(problem)
		info(f"found: [{problem.name}]")
	
	def setup(self, baseDir, lang):
		path=f"{baseDir}/{self.id}"
		os.makedirs(path)
		with open(f"{path}/index.html", "w") as fp:
			fp.write(self.html)
		
		for problem in self.problems:
			problem.setup(path, lang)
			info(f"saved: [{problem.name}]")
		subprocess.call(["code"] + list(map(lambda p: p.solfile, self.problems)))

class CFParser():
	def parse(self, contest_id, creds_file):
		page=doGet(f"https://codeforces.com/contest/{contest_id}/problems")
		soup=BeautifulSoup(page, features="html.parser")
		#check for a countdown
		cntdown=soup.find_all('span', attrs={'class': 'countdown'})
		if len(cntdown) != 0:
			h,m,s=[int(i) for i in str(cntdown[0].string).split(":")]
			t=h * 60 * 60 + m * 60 + s
			while t > 0:
				time.sleep(1)
				t-=1
				sys.stdout.write("\rCountdown: {:02}:{:02}:{:02}".format(int(t / (60 * 60)), int((t % (60 * 60)) / 60), int(t % 60)))
				sys.stdout.flush()
			return CFParser().parse(contest_id, creds_file)
		contest = Contest(contest_id, soup.find_all('div', attrs={'class': 'caption'})[0].string, str(soup))
		for prob in soup.find_all('div', attrs = {'class': 'problemindexholder'}):
			problem = Problem(prob.get('problemindex'), prob.find_all('div', attrs={'class': 'title'})[0].string)
			for test in prob.find_all('div', attrs={'class': 'sample-test'}):
				_inp=""
				for chld in test.findChildren('div', recursive=False):
					if 'input' in chld.get('class'):
						_inp = chld.find_all('pre')[0].get_text('\n')
					if 'output' in chld.get('class'):
						_out = chld.find_all('pre')[0].get_text('\n')
						problem.addTest(html.unescape(_inp), html.unescape(_out))
				# cf brought some changes in 5 dec 2020. above block can be replaced with this below block
				# problem.addTest(
				# 	test.find_all('div', attrs={'class': 'input'})[0].find_all('pre')[0].string,
				# 	test.find_all('div', attrs={'class': 'output'})[0].find_all('pre')[0].string
				# )
			contest.addProblem(problem)
		return contest

class ACParser():
	def parse(self, contest_id, creds_file):
		user,passwd=open(creds_file).read().split(',')
		s=requests.session()
		r=s.get("https://atcoder.jp/login") # get the initial cookies to get the csrf_token
		csrf_tok=unquote(list(filter(lambda x:x.startswith("csrf_token"), requests.utils.dict_from_cookiejar(r.cookies)["REVEL_SESSION"].split("%00")))[0][13:])
		r=s.post(
			f"https://atcoder.jp/login?continue=https%3A%2F%2Fatcoder.jp%2Fcontests%2F{contest_id}%2Ftasks_print",
			{"username": user, "password": passwd.strip(), "csrf_token": csrf_tok}
		)
		soup = BeautifulSoup(r.text, features="html.parser")
		contest=Contest(contest_id, contest_id)
		for prob in soup.find_all('div', attrs={'id': 'main-container'})[0].findChildren('div', attrs={'class': 'row'}, recursive=False)[1].findChildren('div', attrs={'class': 'col-sm-12'}):
			probdiv=prob.findChildren('span', attrs={'class': 'h2'})
			if len(probdiv) != 0:
				problem = Problem(probdiv[0].string.split('-')[0].strip(), probdiv[0].string)
				contest.addProblem(problem)
				inp = ""
				for part in prob.find_all('span', attrs={'class': 'lang-en'})[0].find_all('div', attrs={'class': 'part'}):
					h3=part.find_all('h3')[0]
					if "Sample Input" in h3.string:
						inp=part.find_all('pre')[0].string
					elif "Sample Output" in h3.string:
						problem.addTest(inp, part.find_all('pre')[0].string)
		return contest

class CCParser():
	def parse(self, contest_id, creds_file):
		resp=json.load(doGet(f"https://www.codechef.com/api/contests/{contest_id}"))
		pabstract=[resp['problems'][p] for p in resp['problems']]
		pabstract.sort(key=lambda k: int(k['successful_submissions']), reverse=True)
		ctst=Contest(contest_id, resp['name'])
		i, alpha=0, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		for p in pabstract:
			if p['code'] not in resp['problems_data'] or 'body' not in resp['problems_data'][p['code']]: continue
			problem=Problem(f"{alpha[i]}_{p['code']}", f"{p['code']}. {p['name']}")
			i+=1
			
			pdesc=resp['problems_data'][p['code']]['body'].split("\r\n")
			inp, out, lastLine, _input, _output=False, False, "", "", ""
			for line in pdesc:
				if line.startswith('```'):
					if lastLine.startswith('### Example Input'): inp=True
					elif lastLine.startswith('### Example Output'): out=True
					else:
						if inp: inp=False
						elif out:
							out=False
							problem.addTest(_input, _output)
							_input=_output=""
				else:
					if inp: _input+=line + "\n"
					elif out: _output+=line + "\n"
				lastLine = line
			ctst.addProblem(problem)
		return ctst

class ContestParser():
	# root_folder platform contestid lang
	def run(self, args):
		# check if we have this contest in the current set or archive. if yes, just open them
		paths = [
			f"{args[0]}/{args[1]}/archive/{args[2]}",
			f"{args[0]}/{args[1]}/{args[2]}"
		]
		lang = args[4]
		archdir = ''
		for p in paths:
			if os.path.exists(p):
				archdir = p
		if archdir == '':
			info("Downloading...")
			ctst = parsers[args[1]].parse(args[2], args[3])
			ctst.setup(args[0] + "/" + args[1], lang)
		else:
			info("contest files already exist. opening them")
			toopen = []
			for p in os.listdir(archdir):
				if os.path.isdir(f"{archdir}/{p}"):
					toopen.append(f"{archdir}/{p}/{p}.*")
			subprocess.call(f"code {' '.join(toopen)}", shell=True)

class ContestArchiver():
	def run(self, args):
		shutil.move(f"{args[0]}/{args[1]}/{args[2]}", f"{args[0]}/{args[1]}/archive/{args[2]}")

class CPPRunner():
	def init(self, base):
		if os.path.exists(base + "/sol"):
			os.remove(base + "/sol")
	
	def getCompileCommand(self, base, file, mode):
		cmdline = ["g++", "-o", "sol", "-Wall"]
		if mode == "prod":
			cmdline.append("-DONLINE_JUDGE")
			cmdline.append("-O2")
		else:
			cmdline.append("-g")
			cmdline.append("-fsanitize=address")
		cmdline.append(file)
		return cmdline
	
	def getRunCommand(self, base, file, mode):
		return ["./sol"]

class KotlinRunner():
	def init(self, base):
		if os.path.exists(base + "/sol.jar"):
			os.remove(base + "/sol.jar")
	
	def getCompileCommand(self, base, file, mode):
		return ["/home/mmp/kotlin/kotlinc/bin/kotlinc", file, "-include-runtime", "-d", "sol.jar"]
	
	def getRunCommand(self, base, file, mode):
		return ["java", "-jar", "./sol.jar"]

class PythonRunner():
	def init(self, base):
		pass
	
	def getCompileCommand(self, base, file, mode):
		return ["echo", ""]
	
	def getRunCommand(self, base, file, mode):
		return ["python3", file]

class Runner():
	def run(self, args):
		base = args[0]
		file = args[1]
		mode = args[2]
		fn, ext = os.path.splitext(file)
		if ext == '':
			err("File names with no extensions can't be run")
			return
		runner = langPlugs[ext[1:]]['runner']()

		title(f"Running tests on {base}")
		runner.init(base)
		compileCommand = runner.getCompileCommand(base, file, mode)
		runCommand = runner.getRunCommand(base, file, mode)

		info("> {}{}{}".format(Colors.DIM, ' '.join(compileCommand), Colors.ENDC))
		ret = subprocess.call(compileCommand, cwd=base)
		status("compilation... ", not ret)
		if ret != 0:
			return

		if mode == "custom":
			info("{}> {' '.join(runCommand)}{}".format(Colors.DIM, Colors.ENDC))
			warn("Waiting for input:")
			subprocess.call(runCommand, cwd=base)
			return

		for f in os.listdir(base):
			if f.startswith("in"):

				tid = f.split(".")[1] if "." in f else ""
				cmdline = f"{' '.join(runCommand)} < {f} {'2> last.err | tee last.out' if mode != 'prod' else '> last.out'}"
				title(f"\nRunning test #{tid} {Colors.ENDC}{Colors.DIM}[{cmdline}]{Colors.ENDC}")
				
				# setup input and expected output
				jstatus=1
				try: exp=open(base + "/out" + (f".{tid}.txt" if tid != "" else "")).readlines()
				except:
					exp=["<no expected output>\n"]
					jstatus=2
				statuses=["FAILED", "SUCCESS", "NOT JUDGED"]
				if mode != "prod":
					label("input")
					print(open(base + "/" + f).read())
					label("expected:")
					for l in exp:
						sys.stdout.write(l)
					label("\noutput:")

				# run the code with tee
				start=time.time()
				ret=subprocess.call(cmdline, cwd=base, shell=True)
				end=time.time()
				
				# now do the diff (act.out will only have the stdout)
				out = open(f"{base}/last.out").readlines()

				if jstatus != 2:
					for tup in zip_longest(out, exp, fillvalue=''):
						if tup[0].strip() != tup[1].strip():
							jstatus = 0
							break
				
				if mode != "prod":
					err = open(f"{base}/last.err").readlines()
					if err:
						label('debug info: ')
						for l in err: print(l.strip())
				status(f"", (jstatus, statuses[jstatus]), "({:.3f}s.)".format(end-start))
		print('\n')

class MatGraphVisualizer():
	def doStuff(self, args):
		matrix=[[int(i) for i in line.split(' ')] for line in args[0].splitlines()]
		data=""
		for r in range(len(matrix)):
			for c in range(len(matrix[r])):
				print(f"{r+1} -> {c+1} [label=\"{matrix[r][c]}\"]")

def writeTempData(ifile, data):
	f="/tmp/" + ifile.replace('/', '_') + ".md"
	fp=open(f, 'w')
	fp.write("```graphviz\n")
	fp.write(data)
	fp.write("```\n")
	fp.close()
	return f

class AdjGraphVisualizer():
	def doStuff(self, args):
		lines=args[0].splitlines()
		data=""
		data+=("digraph {\n")
		for i in range(len(lines)):
			edge=lines[i].strip()
			chu=[int(i) for i in edge.split(' ')]
			data+=(f"{chu[0]} -> {chu[1]} [label=\"{chu[2] if len(chu) > 2 else ''}\"]\n")
		data+=("}\n")
		subprocess.call(['code', writeTempData(args[0], data)])

class AdjListGraphVisualizer():
	def doStuff(self, args):
		lines=args[0].splitlines()
		data=""
		data+=("digraph {\n")
		for i in range(len(lines)):
			edge=lines[i].strip()
			data+='\n'.join([f"{i+1} -> {v}\n" for v in edge.split(' ')[1:]])
		data+=("}\n")
		subprocess.call(['code', writeTempData(args[0], data)])

visualizers = {
	"graph-mat" : MatGraphVisualizer(), 
	"graph-adj": AdjGraphVisualizer(),
	"graph-adj-list": AdjListGraphVisualizer()
}

langPlugs = {
	'kt': {
		'runner': KotlinRunner
	},
	'cpp': {
		'runner': CPPRunner,
	},
	'py': {
		'runner': PythonRunner
	}
}

class InputVisualizer():
	def run(self, args):
		visualizers[args[0]].doStuff(args[1:])

parsers = { "cf" : CFParser(), "ac" : ACParser(), "cc" : CCParser() }
commands = { "setup": ContestParser(), "test": Runner(), "archive": ContestArchiver(), "viewin": InputVisualizer() }

commands[sys.argv[1]].run(sys.argv[2:])
