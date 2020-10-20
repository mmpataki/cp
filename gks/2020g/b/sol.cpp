#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	int p = 1;
	while(t--)  {
		int n; cin >> n;
		const int R = 2 * n -1;
		long long int sums[R] = {0}, mx = 0, t, sum=0;
		int x = n-1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cin >> t;
				if(i > j) {
					x = n - 1 - (i - j);
				} else if (j > i) {
					x = n - 1 + (j - i);
				} else {
					x = n - 1;
				}
				// cout << ":::" << x << endl;
				sums[x] += t;
			}
		}
		for(int i=0; i < (2  * n - 1); i++) {
			// cout << "::" << sums[i] << endl;
			sum = max(sums[i], sum);
		}
		cout << "Case #" << p++ << ": " << sum << endl;
	}
}

/**

  0 1 2 3 4 5
0 x x x x x x
1 x x x x x x
2 x x x x x x
3 x x x x x x
4 x x x x x x
5 x x x x x x

*/
