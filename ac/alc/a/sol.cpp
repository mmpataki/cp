#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#ifdef LOCAL
#define D(x) printf( #x ": ", x)
#else
#define D(x) 
#endif

class dsu {
	vector<int> v;
public:
	dsu(int siz) {
		v.resize(siz);
		for(int i = 0; i < siz; i++) {
			v[i] = i;
		}
	}
	int find(int a) {
		if(v[a] != a) {
			v[a] = find(v[a]);
		}
		return v[a];
	}
	void uni(int a, int b) {
		v[find(a)] = find(b);
	}
};

int main(int argc, char ** argv) {
	
	int n, q;
	cin >> n >> q;
	dsu d(n);
	int t, u, v;
	while(q--) {
		cin >> t >> u >> v;
		if(!t) {
			d.uni(u, v);
		} else {
			cout << (d.find(u) == d.find(v)) << endl;
		}
	}
}
