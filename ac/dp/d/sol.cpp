#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]"; }

vector<pair<int, int>> items;
int dp[100][100000];

int solve(int n, int cur, int w, int W) {
	D(n)D(cur)D(w)D(W) cout << endl;
	if(cur >= n)
		return 0;
	if(dp[cur][w] != -1)
		return dp[cur][w];
	if(w + items[cur].first > W)
		return 0;

	//take this item
	lint x1 = items[cur].second + solve(n, cur+1, w + items[cur].first, W);
	
	//take the other item
	lint x2 = solve(n, cur+1, w, W);
	
	dp[cur][w] = max(x1, x2);
	return dp[cur][w];
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, W;
	cin >> n >> W;
	
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		items.push_back(make_pair(x, y));
	}
	
	sort(items.begin(), items.end());
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<W; j++) {
			dp[i][j] = -1;
		}
	}
	
	cout << solve(n, 0, 0, W) << endl;
}
