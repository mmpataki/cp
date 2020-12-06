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
	
	int n, possible=0;
	string s;
	cin >> n >> s;

	string x = "110";
	for(int i = 0; i < 3; i++) {
		int cnt=0;
		for(int j = 0; i+j < 3; j++) {
			if(s[j] == x[i+j]) {
				cnt++;
			}
		}
		if(cnt == (3 - i)) {
			possible = (3-i);
			break;
		}
	}

	if(!possible) {
		cout << 0 << endl;
		return 0;
	}

	X(possible);

	int repeat = 0, lasti;
	for(int i = possible; i < n; i+=3) {
		lasti=i;
		for(int j = 0; j < 3 && (i + j < n); j++) {
			if(x[j] != s[i+j]) {
				possible = 0;
				break;
			}
		}
		repeat++;
	}

	X(repeat)

	if(!possible) {
		cout << 0 << endl;
		return 0;
	}

	int totLen = (possible > 0) + (repeat) + (lasti < n ? n - lasti : 0);

	X(totLen)

	cout << (10000000000ll / totLen) << endl;
}

/**

110110110110110110110110110110

1101


 */