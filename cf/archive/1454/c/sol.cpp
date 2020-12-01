#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L "(" << __FUNCTION__ << ":" << __LINE__ << ") "
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
	
	int q;
	cin >> q;
	
	while(q--) {
		int n;
		cin >> n;

		// last index
		int LI[n+1], ANS[n+1], tt;
		for(int i = 0; i < n + 1; i++) { LI[i] = -1; ANS[i] = -1; }

		for(int i = 0; i < n; i++) {
			cin >> tt;
			if(ANS[tt] == -1) {
				ANS[tt] = 1;
			}
			if(LI[tt] != i - 1) {
				ANS[tt]++;
			}
			LI[tt] = i;
		}

		ANS[tt]--;

		int ans = INT_MAX;
		for(int i = 1; i < n + 1; i++) {
			if(LI[i] < 0) continue;
			ans = min(ans, ANS[i]);
		}

		cout << (ans) << endl;
	}
}
