#include <bits/stdc++.h>
using namespace std;

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d1, v1, d2, v2, p;
	cin >> d1 >> v1 >> d2 >> v2 >> p;

	int cost=0;

	// starting delay
	cost += min(d1-1, d2-1);

	// first starter gain
	if(d1 != d2) {
		p -= abs(d1 - d2) * (d1 < d2 ? v1 : v2);
		cost += abs(d1 - d2);
	}

	// together time
	cost += (p / (v1 + v2)) + ((p % (v1 + v2)) > 0);
	cout << cost << endl;
}

