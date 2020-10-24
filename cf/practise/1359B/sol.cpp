#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	
	char a[100][1001];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	int ans=0;
	
	for(int i=0; i<n; i++) {
		char *p1 = a[i], *p2;
		while(*p1) {
			while(*p1 && *p1 != '.')
				p1++;
			p2 = p1;
			while(*p2 && *p2 == '.')
				p2++;
			int s1 = ((p2 - p1) / 2) * y + ((p2 - p1) / 2) * x;
			int s2 = ((p2 - p1) * x);
			ans += min(s1, s2);
			p1 = p2;
		}
	}
	cout << ans << '\n';
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		solve();
	}
	
}
