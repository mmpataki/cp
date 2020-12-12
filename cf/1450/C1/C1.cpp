#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L	__FUNCTION__ << ":" << __LINE__
#define X(x) { cout << F_AND_L << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << F_AND_L __VA_ARGS__ << endl;
#define PC(a) { cout << F_AND_L << " " << #a << "=["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << F_AND_L << " " << #a << "=["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }
#else
#define X(x)
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

#define rep(i, s, e) for(int i=s; i<e; i++)
#define reps(i, s, e, stp) for(int i=s; i<e; i+=stp)
#define per(i, s, e) for(int i=e; i>=0; i--)
#define pers(i, s, e, stp) for(int i=e; i>=0; i+=stp)
#define F(i, n) for(int i=0; i<n; i++)
#define R(i, n) for(int i=n-1; i>=0; i--)

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		char b[n][n+1];
		for(int i = 0; i < n; i++) { cin >> b[i]; }

		int r[n], c[n], k=0;
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(r));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				r[i]+=(b[i][j] == 'X');
				c[j]+=(b[i][j] == 'X');
				k+=(b[i][j] != '.');
			}
		}
		PA(r, 0, n)
		PA(c, 0, n)
		int rr=0, cc=0;
		int cntr=0;
		while(rr < n && cc < n) {
			while(rr < n && r[rr] != n)
				rr++;
			while(cc < n && c[cc] != n)
				cc++;
			S(D(rr) D(cc))
			if(rr >= n && cc >= n)
				break;
			if(rr >= n) {
				if(cc >= n) {
					break;
				} else {
					b[0][cc] = 'O';
				}
			} else {
				if(cc >= n) {
					b[rr][0] = 'O';
				} else {
					b[rr][cc] = 'O';
				}
			}
			rr++;
			cc++;
			cntr++;
		}

		X(k / 3)
		X(cntr)
		for(int i = 0; i <n; i++) {
			cout << b[i] << endl;
		}
	}
}
