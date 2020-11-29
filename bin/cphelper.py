import os
import sys
import urllib2
import urllib
import shutil
import subprocess
import requests
from subprocess import check_output
from bs4 import BeautifulSoup
from itertools import izip_longest
from time import time

class Problem():
	def __init__(self, id, name, time=0, memory=0):
		self.id = id
		self.name = name
		self.time = time
		self.memory = memory
		self.tests = []

	def addTest(self, inp, out):
		self.tests.append([str(inp).strip(), str(out).strip()])

	def setup(self, baseDir):
		ppath = baseDir + "/" + self.id
		try: os.makedirs(ppath)
		except: return

		# copy the template
		shutil.copyfile(baseDir + "/../../template.cpp", ppath + "/" + self.id +".cpp")

		# copy the input and output files
		i = 0
		for test in self.tests:
			fp=open(ppath + "/" + "in." + str(i) + ".txt", "w")
			fp.write(test[0])
			fp.close()
			fp=open(ppath + "/" + "out." + str(i) + ".txt", "w")
			fp.write(test[1])
			fp.close()
			i+=1

	def __str__(self):
		return str({ "id" : self.id, "name" : self.name, "tests": self.tests})

class Contest():
	def __init__(self, id, name):
		self.id = id
		self.name = name
		self.problems = []

	def addProblem(self, problem):
		self.problems.append(problem)
	
	def setup(self, baseDir):
		path=baseDir + "/" + self.id
		for problem in self.problems:
			problem.setup(path)
	
	def __str__(self):
		return str({"id": self.id, "name": self.name, "problems": self.problems})

class CFParser():
	def parse(self, contest_id, creds_file):
		url="https://codeforces.com/contest/{}/problems".format(contest_id)
		page=urllib2.urlopen(url)
		soup=BeautifulSoup(page, features="html.parser")
		contest = Contest(contest_id, soup.find_all('div', attrs={'class': 'caption'})[0].string)
		for prob in soup.find_all('div', attrs = {'class': 'problemindexholder'}):
			problem = Problem(prob.get('problemindex'), prob.find_all('div', attrs={'class': 'title'})[0].string)
			for test in prob.find_all('div', attrs={'class': 'sample-test'}):
				problem.addTest(
					test.find_all('div', attrs={'class': 'input'})[0].find_all('pre')[0].string,
					test.find_all('div', attrs={'class': 'output'})[0].find_all('pre')[0].string
				)
			contest.addProblem(problem)
		return contest

class ACParser():
	def parse(self, contest_id, creds_file):
		user,passwd=open(creds_file).read().split(',')
		s=requests.session()
		r=s.get("https://atcoder.jp/login") # get the initial cookies to get the csrf_token
		csrf_tok=urllib.unquote(list(filter(lambda x:x.startswith("csrf_token"), requests.utils.dict_from_cookiejar(r.cookies)["REVEL_SESSION"].split("%00")))[0][13:])
		r=s.post(
			"https://atcoder.jp/login?continue=https%3A%2F%2Fatcoder.jp%2Fcontests%2F{}%2Ftasks_print".format(contest_id),
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

# helper stuff
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

def doPrint(x, color=""):
	print(color + x + Colors.ENDC)
def info(x):
	doPrint(x.rstrip())
def err(x):
	doPrint(x.rstrip(), Colors.FAIL + Colors.BOLD)
def warn(x):
	doPrint(x.rstrip(), Colors.WARNING + Colors.BOLD)
def label(x):
	doPrint(x.rstrip(), Colors.OKBLUE + Colors.BOLD + Colors.ITALIC)
def status(msg, res_and_msg, extra=""):
	colors=[Colors.FAIL, Colors.OKGREEN, Colors.WARNING]
	stdmsgs=["FAILED", "SUCCESS"]
	color,tok=(colors[res_and_msg[0]],res_and_msg[1]) if type(res_and_msg) is tuple else (colors[res_and_msg], stdmsgs[res_and_msg])
	doPrint(Colors.BOLD + msg + "... " + color + tok + Colors.HEADER + " " + extra + Colors.ENDC)

# parser registry
parsers={
	"cf" : CFParser(),
	"ac" : ACParser()
}

class ContestParser():
	def parse(self, args):
		ctst = parsers[args[1]].parse(args[2], args[3])
		ctst.setup(args[0] + "/" + args[1])
		return self

class Runner():
	def run(self, args):
		base = args[0]
		file = args[1]
		mode = args[2]
		cmdline = ["g++", "-o", "sol", "-Wall"]
		if mode == "prod":
			cmdline.append("-DONLINE_JUDGE")
			cmdline.append("-O2")
		else:
			cmdline.append("-g")
			cmdline.append("-fsanitize=address")
		cmdline.append(file)

		info("> {}{}{}".format(Colors.DIM, ' '.join(cmdline), Colors.ENDC))
		ret = subprocess.call(cmdline, cwd=base)
		status("compilation", not ret)

		if mode == "custom":
			info("{}> ./sol{}".format(Colors.DIM, Colors.ENDC))
			warn("Waiting for input:")
			subprocess.call(["./sol"], cwd=base)
			return

		for f in os.listdir(base):
			if f.startswith("in"):
				tid = f.split(".")[1] if "." in f else ""
				info("> {}./sol < {}{}".format(Colors.DIM, f, Colors.ENDC))
				start=time()
				out=check_output(["./sol"], cwd=base, stdin=open(base + "/" + f))
				end=time()
				jstatus=1
				try: exp=open(base + "/out" + ("." + tid + ".txt" if tid != "" else "")).readlines()
				except:
					exp=["<no expected output>\n"]
					jstatus=2
				statuses=["FAIL", "SUCCESS", "NOT JUDGED"]
				if jstatus != 2:
					for tup in izip_longest(out.split("\n"), exp, fillvalue=''):
						if tup[0].strip() != tup[1].strip():
							jstatus = 0
							break
				status("testcase #" + tid, (jstatus, statuses[jstatus]), "({:.3f}s.)".format(end-start))
				if jstatus == 0 or mode != "prod":
					label("input")
					print(open(base + "/" + f).read())
					label("expected:")
					for l in exp:
						sys.stdout.write(l)
					label("\noutput:")
					print(out)

class CPHelper():
	def doJob(self, args):
		if args[0] == "setup":
			ContestParser().parse(args[1:])
		elif args[0] == "test":
			Runner().run(args[1:])

CPHelper().doJob(sys.argv[1:])
