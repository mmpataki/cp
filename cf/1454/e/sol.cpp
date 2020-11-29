#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L	<< __FUNCTION__ << ":" << __LINE__
#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << F_AND_L << __VA_ARGS__ << endl;
#define PC(a) { cout << F_AND_L << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << F_AND_L << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }
#else
#define X(x)
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

#define rep(i, n) for(int i=0; i<n; i++)

typedef struct {
	vector<int> paths;
	vector<int> children;
} node;


// just compute the path lengths
void dfs(vector<node> G, int cur, int uu, int uv, int *visited) {
	if(visited[cur] && G[cur].children.size() == 0) {
		return;
	}
	visited[cur] = 1;
	for(auto child : G[cur].children) {
		dfs(G, child, uu, uv, visited);
	}
	visited[cur] = 0;

	// now process this node
	int len=1;
	G[cur].paths.push_back(G[cur].children.size());
	while (true)
	{
		if(len != 1) {
			G[cur].paths.push_back(0);
		}
		for(auto child: G[cur].children) {
			if(G[child].paths.size() >= len)
				G[cur].paths[len] += G[child].paths[len];
		}
	}
	
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;

		int degree[n+1];
		rep(i, n+1) degree[i]=0;

		vector<node> G(n+1);

		int eu, ev;
		rep(i, n) {
			int tu, tv, u, v;
			cin >> tu >> tv;

			// make sure the edges are from small to large index vertex
			u=min(u, v);
			v=max(u, v);
			
			G[u].children.push_back(v);
			G[v].children.push_back(u);

			degree[u]++;
			degree[v]++;

			// that extra edge in the graph
			if(degree[u] == 2 && degree[v] == 2) {
				eu = u; ev = v;
			}
		}

		int visited[n+1];
		rep(i, n+1) visited[i]=0;

		dfs(G, 1, eu, ev, visited);
		cout << ans << endl;
	}
}

/**

*/