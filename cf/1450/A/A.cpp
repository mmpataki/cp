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
		string s;
		cin >> n >> s;
		int T[256];
		memset(T, 0, sizeof(T));
		for(int i = 0; i <n; i++) {
			T[s[i]]++;
		}
		char *d = "bugyrt";
		char b[n+1];
		b[n]=0;
		int k=0;
		int T1[256];
		memset(T1, 0, sizeof(T1));
		for(int i=0; i<6; i++) {
			T1[d[i]]++;
			for(int j=0; j<T[d[i]]; j++) {
				b[k++] = d[i];
			}
		}
		for(int i='a'; i<='z'; i++) {
			if(T1[i]) continue;
			for(int j=0; j<T[i]; j++) {
				b[k++] = i;
			}
		}

		cout << b << endl;
	}
	
}
