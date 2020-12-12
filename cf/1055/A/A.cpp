#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, s; cin >> n >> s;
	int a[n], b[n];

	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];

	int crossOver = b[s-1];
	if(crossOver) {
		crossOver = 0;
		for(int i=s; i<n; i++) {
			if(a[i] == 1 && b[i] == 1) {
				crossOver = 1;
				break;
			}
		}
	}

	cout << ((a[0] == 1 && (a[s-1] == 1 || crossOver)) ? "YES" : "NO") << endl;
}
