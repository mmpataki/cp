#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#ifdef LOCAL
#define D(x) { cout << "[" << #x << "=" << x << "]"; }
#else
#define D(x) {}
#endif

int main(int argc, char ** argv) {
	
	int t;
	cin >> t;
	
	while(t--) {		
		
		lint x, s=0;
		cin >> x;
		
		while(x > 1) {
			D(x);

			if(x % 5 == 0) {
				x /= 5;
				s += 3;
			} else if(x % 3 == 0) {
				x /= 3;
				s += 2;
			} else if(x % 2 == 0) {
				x /= 2;
				s += 1;
			} else {
				s = -1;
				break;
			}
		}
		
		cout << s << endl;
	}
	
}
