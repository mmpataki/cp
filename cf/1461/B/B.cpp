#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int r, c;
		cin >> r >> c;
		char b[r][c+1];
		for(int i=0; i<r; i++) cin >> b[i];

		int ll[r][c], rl[r][c];
		for(int i=0; i<r; i++) {
			int lcntr=0, rcntr=0;
			for(int j=0; j<c; j++) {
				lcntr += (b[i][j] == '*') ? 1 : -lcntr;
				rcntr += (b[i][c-1-j] == '*') ? 1 : -rcntr;
				ll[i][j] = lcntr;
				rl[i][c-j-1] = rcntr;
			}
		}

		long long int ans=0;
		for(int i=0; i<r; i++) {
			for(int j=0; j<c; j++) {
				if(b[i][j] == '*') {
					for(int k=1; i+k-1<r; k++) {
						if(ll[i+k-1][j] >= k && rl[i+k-1][j] >= k) {
							ans++;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	
}
