#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) printf( #x ": ", x)

int main(int argc, char ** argv) {
	
	int n, k;
	cin >> n >> k;
	
	int cnt  = 0, t=0;
	for(int i=0; i<n; i++) {
		cin >> t;
		if(5 - t >= k) {
			cnt++;
		}
	}
	
	cout << (cnt / 3) << endl;
}
