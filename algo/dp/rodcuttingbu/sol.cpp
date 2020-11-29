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

#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i,s,n) for(int i=s; i<=n; i++)
#define per(i, n) for(int i=n-1; i>=0; i--)

int main(int argc, char ** argv) {
	int n=4;
	int a[]={0,1,5,8,9,10,17,17,20,24,30};

	int sol[12];
	int dp[12];
	rep(i, 12) dp[i]=-1;

	dp[0]=0;
	repx(i, 1, n) {
		PA(dp, 1, 11)
		repx(j, 1, i) {
			if(dp[i] < dp[i-j] + a[j]) {
				dp[i] = dp[i-j]+a[j];
				sol[i] = j;
			}
		}
	}
	cout << dp[n] << endl;
	int i=n;
	while(i > 0) {
		cout << sol[i] << " ";
		i -= sol[i];
	}
}
