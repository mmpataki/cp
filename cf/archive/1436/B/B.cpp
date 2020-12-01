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
		int a[n][n];
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) a[i][j] = 0;
		for(int i = 0; i < n; i++) {
			a[i][i] = a[i][n - i -1] = 1;
		}
		if(n & 1) {
			a[n/2-1][n/2] = a[n/2+1][n/2] = a[n/2][n/2+1] = a[n/2][n/2-1] = 1;
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
	}
}
