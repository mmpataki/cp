#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define rep(i, n) for(int i=0; i<n; i++)
#define per(i, n) for(int i=p;i>=0; i--)
#define si(x) scanf("%d", &x);

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	lint a[n];
	
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	int ans=0, t=0, p = -1;
	rep(i, n) {
		if(a[i] > p) {
			t++;
		} 
		ans = max(ans, t);
		if(a[i] <= p) {
			t = 1;
		}
		p = a[i];
	}
	
	cout << ans << endl;
}
