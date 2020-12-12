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

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll ans=0;
	int a1, a2;
	cin >> a1 >> a2;
	
	while(true) {
		if(a1 < 2 && a2 < 2)
			break;
		ans++;
		if(a1 < a2) {
			a1+=1;
			a2-=2;
		} else {
			a2+=1;
			a1-=2;
		}
	}
	cout << (ans+1) << endl;
}
