#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L __FUNCTION__ << ":" << __LINE__
#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << F_AND_L __VA_ARGS__ << endl;
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
		int n, k;
		cin >> n >> k;

		int a[n], T[101];
		memset(T, 0, sizeof(T));
		for(int i = 0; i < n; i++) { 
			cin >> a[i];
			T[a[i]]++;
		}

		int ans=INT_MAX, tmp;
		for(int i=1; i<101; i++) {
			if(!T[i]) continue;
			tmp = 0;
			for(int j = 0; j < n; j++) {
				if(a[j] != i) {
					tmp++;
					j += k-1;
				}
			}
			ans = min(ans, tmp);
		}
		cout << ans << endl;
	}
}
