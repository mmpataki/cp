#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << #x << ": " << x << endl; }

int main(int argc, char ** argv) {
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		lint mx=0, mxi = -2;
		lint a[n];
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		for(int i=0; i<n; i++) {
			if(mx < a[i] && ((i-1 >= 0 && a[i-1]<a[i]) || (i+1 < n && a[i]>a[i+1]))) {
				mxi = i;
				mx = a[i];
			}
		}
		cout << (mxi + 1) << endl;
	}
}
