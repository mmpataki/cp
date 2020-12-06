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
	
	int n;
	cin >> n;
	string s;
	cin >> s;

	int x=0, y=0, ans=0, lastQuad=-1, curQuad=0;
	for(int i = 0; i < n; i++) {
		(s[i]=='U') ? y++ : x++;
		curQuad = x > y ? 0 : (x < y ? 1 : lastQuad);
		if(lastQuad != -1 && lastQuad != curQuad) {
			ans++;
		}
		lastQuad = curQuad;
	}
	cout << ans << endl;
}
