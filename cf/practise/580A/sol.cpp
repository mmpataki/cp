#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int ans=0, x, t=0, p=-1;
	for(int i=0; i<n; i++) {
		cin >> x;
		if(x >= p) {
			t++;
		}
		ans = max(t, ans);
		if (x < p) {
			t = 1;
		}
		p = x;
	}
	cout << ans << endl;
}
