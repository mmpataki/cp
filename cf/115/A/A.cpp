#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	vector<vector<int>> G(n+1);
	for(int i=1; i<=n; i++) {
		cin >> t;
		if(t == -1) t++;
		G[t].push_back(i);
	}

	int cur, lvl;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	while(q.size()) {
		tie(cur, lvl) =  q.front();
		q.pop();
		for(auto chld : G[cur]) {
			q.push(make_pair(chld, lvl+1));
		}
	}

	cout << lvl << endl;
}
