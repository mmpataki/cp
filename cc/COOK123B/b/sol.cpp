#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int l,r;
		cin >> l >> r;
		if(r % l == 0) {
			cout << "-1" << endl;
		} else {
			cout << r << endl;
		}
	}
}
