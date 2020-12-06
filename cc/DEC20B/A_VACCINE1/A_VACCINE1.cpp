#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L	<< __FUNCTION__ << ":" << __LINE__
#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << F_AND_L << __VA_ARGS__ << endl;
#define PC(a) { cout << F_AND_L << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << F_AND_L << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }
#else
#define X(x)
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d1, v1, d2, v2, p;
	cin >> d1 >> v1 >> d2 >> v2 >> p;

	int extra = abs(d1 - d2);
	int left = extra * ((d1 < d2) ? v1 : v2);

	int q = (p - left) / (v1 + v2);
	int r = (p - left) % (v1 + v2);

	cout << (min(d1-1, d2-1) + extra + q + (r > 0)) << endl;
}

