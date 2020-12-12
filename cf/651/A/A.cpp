#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;

	int ans = 0;
	while(true) {
		if(a < 1 || b < 1 || (a + b < 3))
			break;
		ans++;
		if(a - 2 < 1) {
			a += 1;
			b -= 2;
		} else {
			b += 1;
			a -= 2;
		}
	}
	cout << ans << endl;
}
