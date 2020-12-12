#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	ll totWid=0;
	int w[n], h[n], hc[n];
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> h[i];
		hc[i] = h[i];
		totWid += w[i];
	}
	sort(hc, hc+n);

	for(int i = 0; i < n; i++) {
		cout << (totWid - w[i]) * ((h[i] == hc[n-1]) ? hc[n-2] : hc[n-1]) << " \n"[(i+1) == n];
	}
}
