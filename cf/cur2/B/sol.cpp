#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}

int t[500][500];

void solve() {
	int m, n;
	cin >> n >> m;
	int op[n];
	map<int, int> s;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> t[i][j];
			if(!j)
				s[t[i][j]] = i;
		}
	}
	int slv=0, x;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> x;
			if(slv == 2) continue;
			if(slv == 1 || (!j && s.find(x) != s.end())) {
				op[j] = x;
				slv = 1;
			}
		}
		if(slv == 1) {
			slv = 2;
		}
	}
	for(int i=0; i<n; i++) {
		int r = s[op[i]];
		for(int j=0; j<m; j++) {
			printf("%d%c", t[r][j], j+1==m ? '\n' : ' ');
		}
	}
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tt;
	cin >> tt;
	
	while(tt--) {
		solve();
	}
	
}
