#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#ifdef LOCAL
#define D(x) printf( #x ": ", x)
#else
#define D(x) 
#endif

void init(int *u, int n) {
	for(int i=0; i<n; i++) u[i] = i;
}

int find(int *u, int a) {
	if(u[a] != a) {
		u[a] = find(u, u[a]);
	}
	return u[a];
}

void uni(int *u, int a, int b) {
	u[find(u, a)] = find(u, b);
}

int main(int argc, char ** argv) {
	
	int n, q;
	cin >> n >> q;
	int a[n];
	init(a, n);
	int t, u, v;
	while(q--) {
		cin >> t >> u >> v;
		if(!t) {
			uni(a, u, v);
		} else {
			cout << (find(a, u) == find(a, v)) << endl;
		}
	}
}
