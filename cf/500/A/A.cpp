#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, t;
	cin >> n >> t;

	vector<int> G(n+1);

	for(int u=1; u<n; u++) {
		int v;
		cin >> v;
		G[u] = (u + v);
	}
	G[n] = -1;

	queue<int> Q;
	Q.push(1);
	while(Q.size()) {
		int cur = Q.front(); Q.pop();
		int nxt = G[cur];
		if(nxt == t) {
			cout << "YES" << endl;
			return 0;
		}
		if(nxt != -1)
			Q.push(nxt);
	}
	cout << "NO" << endl;
}
