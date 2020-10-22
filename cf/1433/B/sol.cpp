#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) printf( #x ": ", x)

int main(int argc, char ** argv) {
	
	int t; cin >> t;
	
	while(t--) {
		int n; cin >> n;
		
		int a[n];
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		
		int sum=0, gap=0, oneseen = 0;
		for(int i=0; i<n; i++) {
			if(a[i]) {
				if(!oneseen) {
					oneseen = 1;
				} else {
					sum += gap;
					gap = 0;
				}
			} else {
				if(oneseen)
					gap++;
			}
		}
		
		cout << sum << endl;
	}
}
