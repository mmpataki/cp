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
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;

		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int ans = 0, mx = 0, mxi = 0, delta=0, act = 0;
		for(int i = 1; i < n; i++) {
			X(delta)
			int nn = a[0] - (delta + a[i]);
			X(abs(nn))
			delta += a[0] - a[i];
			if(mx < abs(delta)) {
				mxi =  i;
				mx = abs(nn);
				act = nn;
			}
		}
		X(mx)
		X(act)
		X(mxi)
		a[mxi] += act;

		delta = 0;
		for(int i = 0; i < n; i++) {
			int nn = a[0] - (delta + a[i]);
			ans += abs(nn);
			delta += a[0] - a[i];	
		}

		cout << ans << endl;
	}
	
}
