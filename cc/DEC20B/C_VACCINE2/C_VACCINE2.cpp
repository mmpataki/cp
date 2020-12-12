#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, D;
		cin >> n >> D;

		int a[n];
		for(int i = 0; i <n; i++) cin >> a[i];

		int risk=0;
		for(int i = 0; i <n; i++) risk += (a[i] < 10 || a[i] > 79);

		#define DD(r, t) (((r) / t) + (((r) % t) > 0))

		cout << (DD(risk, D) + DD(n-risk, D)) << endl;
	}
}
