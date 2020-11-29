#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L __FUNCTION__ << ":" << __LINE__ << " "
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

int p[] = {0,1,5,8,9,10,17,17,20,24,30};
int n = 10;
int dp[12];

int solve(int len) {
	if(len <= 0) return 0;
	X(len)
	PA(dp, 0, 12)
	if(dp[len] != -1) return dp[len];
	int sol = -1;
	for(int i=1; i<=len; i++) {
		sol = max(sol, p[i] + solve(len - i));
		X(sol)
	}
	dp[len]=sol;
	return sol;
}

int main(int argc, char ** argv) {
	for(int i=0; i<=n+1; i++) dp[i]=-1;
	cout << solve(n) << endl;
}
