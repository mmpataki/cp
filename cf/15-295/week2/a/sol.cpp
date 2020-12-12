#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifdef MMPATAKI_DEBUG
#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << __FUNCTION__ << " " __VA_ARGS__ << endl;
#define PC(a) { cout << __FUNCTION__ << " " << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << __FUNCTION__ << " " << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }   
#define PAA(a,n,m) { cout << __FUNCTION__ << " " << #a << ":\n"; for(int __xmmp1=0; __xmmp1<n; __xmmp1++) { for(int __xmmp2=0; __xmmp2<m; __xmmp2++) { cout << a[__xmmp1][__xmmp2] << " "; } cout << endl; } }   
#else
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#define PAA(a,n,m)
#endif

int G[27][26], soli=0;
char sol[25];

int find(int len, int cur) {
	if(len == 0) {
		return 0;
	}
	for(int i=0; i<26; i++) {
		if(G[cur][i] == 0) {
			sol[soli++]='a'+i;
			sol[soli]=0;
			cout << sol << endl;
			return 1;
		}
	}
	for(int i=0; i<26; i++) {
		sol[soli++]='a'+i;
		if(find(len-1, i))
			return 1;
		soli--;
	}
	return 0;
}
int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	char s[21];
	
	for(int i=0; i<n; i++) {
		cin >> s;
		G[26][s[0]-'a']=1;
		for(int j=1; s[j]; j++) {
			G[26][s[j]-'a']=1;
			G[s[j-1]-'a'][s[j]-'a']=1;
		}
	}
	
	PAA(G, 27, 26)
	
	int solf=0;
	for(int i=1; i<22; i++) {
		if(find(i, 26)) {
			solf=1;
			break;
		}
	}
	if(!solf) {
		for(int k=0; s[k]; k++) {
			cout << 'a';
		}
		cout << "a" << endl;
	}
}
