#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		ll a, b;
		cin >> a >> b;
		ll ea = a / 2, oa = a / 2;
		oa += (a & 1);
		ll eb = b / 2, ob = b / 2;
		ob += (b & 1);
		cout << (ea * eb) + (oa * ob) << endl;
	}
}
