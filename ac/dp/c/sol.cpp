#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> dp(3, 0);
	for(int i=0; i<n; i++) {
		
		vector<int> v(3, 0);
		for(int j=0; j<3; j++) {
			cin >> v[j];
		}
		
		vector<int> newdp(3, 0);
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) {
				if(j != k) {
					newdp[j] = max(newdp[j], dp[k]+v[j]);
				}
			}
		}
		dp = newdp;
	}
	cout << max({dp[0], dp[1], dp[2]}) << endl;
}
