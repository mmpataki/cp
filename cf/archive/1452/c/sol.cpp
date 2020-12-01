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
	
	int t;
	cin >> t;
	char a[2 * 100005];
	while(t--) {
		cin >> a;
		int rb=0;
		int sb=0;
		int ans=0;
		for(int i=0; a[i]; i++) {
			if(a[i] == '(') {
				rb++;
			} else if(a[i] == '[') {
				sb++;
			} else if(a[i] == ')' && rb > 0) {
				rb--;
				ans++;
			} else if(a[i] == ']' && sb > 0){
				sb--;
				ans++;
			}
		}
		cout << ans << endl;
	}
	
}
