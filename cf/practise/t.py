import sys
for x in sys.argv:
	if x == "t.py":
		continue
	print(
		"<a href='https://codeforces.com/problemset/problem/{}/{}'>{}</a></br>"
			.format(x[0:-1], x[-1], x)
	)
