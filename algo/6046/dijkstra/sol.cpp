#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L	__FUNCTION__ << ":" << __LINE__
#define X(x) { cout << F_AND_L <<  "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << F_AND_L __VA_ARGS__ << endl;
#define PC(a) { cout << F_AND_L << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << F_AND_L << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }
#else
#define X(x)
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

/*
DIJKSTRA(G, S, W, PRED):
	d := [INF]
	Q := G.V
	while Q != NULL_SET:
		u := Q.extract_min()
		for (u, v) in G.E:
			if d[v] > d[u] + W(u, v):
				d[v] = d[u] + W(u, v)
				PRED[v] = u
*/
const ll INF = LONG_LONG_MAX;
void dijkstra(vector<vector<pair<int, ll>>> &G, int v, int s, ll *d, int *path) {
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

int main() {
	int v, e;
	cin >> v >> e;
	vector<vector<pair<int, ll>>> G(v);
	for(int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		--a;
		--b;
		G[a].push_back(make_pair(b, w));
		G[b].push_back(make_pair(a, w));
	}
	ll ans[v];
	int path[v];
	memset(ans, 0x7f, sizeof(ans));
	for(int i = 0; i < v; i++) path[i]=-1;
	PA(ans, 0, v)
	dijkstra(G, v, 0, ans, path);
	if(path[v-1] == -1) {
		cout << -1 << endl;
	} else {
		vector<int> p;
		for(int i=v-1; i != -1; i=path[i]) {
			p.push_back(i+1);
		}
		for(int i=p.size()-1; i>=0; i--) {
			cout << p[i] << ' ';
		}
	}
}
