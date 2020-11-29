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
	
	int a, b, x, y;
	cin >> a >> b >> x >> y;

	int between = 2 * x;
	int up = y;
	int ans;

	// going up
	if(a < b) {
		if(between > up) {
			ans = (b - a) * y + x;
		} else {
			ans = (b - a) * between + x;
		}
	} else if(a > b) {
		if(between > up) {
			ans = max(a - b - 1, 0) * up + x;
		} else {
			ans = max(a - b - 1, 0) * between + x;
		}
	} else {
		ans = x;
	}
	cout << ans << endl;
}
