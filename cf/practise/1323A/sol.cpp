#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}

void solve() {
	int n, x, a[2]={0,0}, s[2][100];
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		s[x % 2][a[x % 2]] = i + 1;
		a[x % 2]++;
	}
	if(a[0] > 0) {
		cout << "1\n" << s[0][0] << '\n';
	} else if (a[1] > 1) {
		cout << "2\n" << s[1][0] << " " << s[1][1] << '\n';
	} else {
		cout << "-1" << '\n';
	}
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
