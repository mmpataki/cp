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

vector<int> topoSort(map<int, vector<pair<int, int>>> &G) {
	vector<int> ret;
	stack<int> stk;
	for(auto v : G) {
		stk.push(v.first);
		if(v.second.size() == 0) {
			ret.push_back(stk.top());
			stk.pop();
		}
		for(auto adj: v.second) {

		}
	}
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int e;
	cin >> e;
	map<int, vector<pair<int, int>>> G;
	for(int i=0; i<e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if(G.find(u) == G.end()) {
			G[u] = {};
		}
		if(G.find(v) == G.end()) {
			G[v] = {};
		}
		G[u].push_back({v, w});
	}

	PC(topoSort(G));
}
