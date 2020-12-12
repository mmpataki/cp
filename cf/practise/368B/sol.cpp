#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifdef DEBUG
#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << __FUNCTION__ << " " __VA_ARGS__ << endl;
#define PC(a) { cout << __FUNCTION__ << " " << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << __FUNCTION__ << " " << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }   
#else
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif
int seen[100001];
int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	int sol[n+1], dist=0;
	for(int i=0; i<100001; i++) seen[i]=0;
	
	for(int i=n-1; i>=0; i--) {
		seen[a[i]]++;
		if(seen[a[i]]==1) {
			dist++;
		}
		sol[i+1]=dist;
	}
	
	for(int i=0; i<m; i++) {
		cin >> n;
		cout << sol[n] << '\n';
	}
}
