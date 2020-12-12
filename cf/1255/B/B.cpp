#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		if(n == 2) {
			cin >> m;
			cout << "-1\n";
			continue;
		}
		vector<pair<int, int>> v(n);
		for(int i = 0; i <n; i++) {
			cin >> v[i].first;
			v[i].second = i+1;
		}
		sort(v.begin(), v.end());
		ll cost=0;
		int cnt=0;
		for(int i = 0; i <2; i++) {
			for(int j = 2; j <n; j++) {
				cost += v[i].first + v[j].first;
				if((++cnt) > m) {
					goto failed;
				}
			}
		}
	failed:
		if(cnt - 1 > m) {
			cout << "-1\n";
			continue;
		} else {
			cost += (m - cnt) * (v[0].first + v[1].first);
			for(int i = 0; i <2; i++) {
				for(int j = 2; j <n; j++) {
					cout << v[i].second << " " << v[j].second << endl;
				}
			}
			while(++cnt <= m) {
				cout << v[0].second << " " << v[1].second << endl;
			}
		}
	}
}
