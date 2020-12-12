#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ax, ay, bx, by, cx, cy;
	cin >> n >> ax >> ay >> bx >> by >> cx >> cy;

	#define DDS(a, b) ((b - a) / abs(b - a))
	#define CHK(a, b, c) ((c - b) && (DDS(c, a) == DDS(c, b)))

	if(CHK(bx, cx, ax) && CHK(by, cy, ay)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
