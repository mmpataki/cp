#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) printf( #x ": ", x)

lint solveT2(int &a, int &b, int &c, int &d, int &e, int &f) {
	int s = min(min(b, c), d);
	b -= s;
	c -= s;
	d -= s;
	return s * f;
}

lint solveT1(int &a, int &b, int &c, int &d, int &e, int &f) {
	int s = min(a, d);
	a -= s;
	d -= s;
	return s * e;
}

int main(int argc, char ** argv) {
	
	int a, b, c, d, e, f;
	cin>> a>> b>> c>> d>> e>> f;
	
	lint sum = 0;
	
	if(e > f) {
		sum+=solveT1(a, b, c, d, e, f);
		sum+=solveT2(a, b, c, d, e, f);
	} else {
		sum+=solveT2(a, b, c, d, e, f);
		sum+=solveT1(a, b, c, d, e, f);
	}
	
	cout << sum << endl;
}
