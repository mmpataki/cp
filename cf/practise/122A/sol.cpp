#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) printf( #x ": ", x)

int main(int argc, char ** argv) {
	
	int t;
	cin >> t;
	
	int d[] = {
			4, 7,
			44, 47, 74, 77,
			444, 447, 474, 477, 744, 747, 774, 777,
			0
		};
		
	for(int i=0; d[i]; i++) {
		if(t % d[i] == 0) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}
