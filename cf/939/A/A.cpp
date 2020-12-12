#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	int g[n+1];

	for(int i=1; i<=n; i++) cin >> g[i];

	for(int i=1; i<=n; i++) {
		if(g[g[g[i]]] == i) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}
