#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) printf( #x ": ", x)

int main(int argc, char ** argv) {
	
	int n, k;
	cin >> n >> k;
	
	lint a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	sort(a, a+n);
	
	if(k > n) {
		cout << "-1" << endl;
	} else {
		cout << a[n - k] << " " << a[n - k] << endl;
	}
}
