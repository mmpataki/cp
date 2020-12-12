#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L	__FUNCTION__ << ":" << __LINE__
#define X(x) { cout << F_AND_L << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << F_AND_L __VA_ARGS__ << endl;
#define PC(a) { cout << F_AND_L << " " << #a << "=["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << F_AND_L << " " << #a << "=["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }
#else
#define X(x)
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

void dijkstra(vector<map<int, ll>> &G, int v, int s, ll *d, int *path) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
	Q.push(make_pair(0, s));
	int visited[v];
	memset(visited, 0, sizeof(visited));
	d[s] = 0;
	while(!Q.empty()) {
		int u = Q.top().second;
		Q.pop();
		if(visited[u]++) continue;
		for(auto uv : G[u]) {
			ll dist = d[u] + uv.second;
			if(dist < d[uv.first]) {
				Q.push(make_pair(d[uv.first] = dist, uv.first));
				path[uv.first] = u;
			}
		}
	}
}

const ll INF = LONG_LONG_MAX;
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;

	vector<map<int, ll>> G(n);
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		if(G[u][v] == 0 || G[u][v] > w) {
			G[u][v] = G[v][u] = w;
		}
	}
	
	vector<ll> t(n);
	int ans = 0;
	for(int i = 0; i < k; i++) {
		ll c, w; cin >> c >> w;
		--c;
		if(G[0][c]) ans++;
		if(G[0][c] == 0 || G[0][c] > w) {
			G[0][c] = G[c][0] = w;
		}
	}

	ll w[n];
	int p[n];
	for(int i = 0; i < n; i++) w[i] = INF, p[i] = -1;

	dijkstra(G, n, 0, w, p);

	PA(w, 0, n)
	PA(t, 0, n)

	for(int i = 1; i < n; i++) {
		if(!t[i]) continue;
		if(t[i] == w[i]) {
			X(++ans);
		}
	}

	cout << ans << endl;
}
