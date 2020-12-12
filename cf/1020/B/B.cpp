#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int a[n+1];
	for(int i=1; i<=n; i++) cin >> a[i];

	for(int i=1; i<=n; i++) {
		int v[n+1];
		memset(v, 0, sizeof(v));
		v[i]=1;
		int cur;
		for(cur=a[i]; cur!=i; cur=a[cur]) {
			if(v[cur]++) {
				break;
			}
		}
		cout << cur << " ";
	}
}
