#include <bits/stdc++.h>
using namespace std;
#define MOD (1000000000+9)

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++) 
		cin >> a[i];
	int y=n, x=1;
	int t=0;
	vector<pair<int, int>> sol;
	for(int i=n-1; i>=0; i--) {
		if(a[i] == 0) {
			y--;
		} else if (a[i] == 1) {
			sol.push_back(make_pair(x, y));
			x++;
		} else if (a[i] == 2) {
			sol.push_back(make_pair(x, y));
			x++;
			y--;
		} else {
		}
	}
}

