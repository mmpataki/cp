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

#define rep(i, n) for(int i=0; i<n; i++)

int longestCommonSubstring(string a, string b) {
	int dp[a.length() + 1][b.length() + 1];
	rep(i, b.length()+1) {
		dp[0][i] = 0;
	}
	rep(i, a.length()+1) {
		dp[i][0] = 0;
	}
	int ans=0;
	for(int i = 1; i <= a.length(); i++) { 
		for(int j = 1; j <= b.length(); j++) {
			dp[i][j] = dp[i-1][j-1] + (a[i-1] == b[j-1]);
			ans=max(ans, dp[i][j]);
		}
	}
	return ans;
}

int main(int argc, char ** argv) {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		cout << longestCommonSubstring(a, b) << endl;
	}
}

/**

*/