#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		int a[n], b[n], i=0;
		for(i=0; i<n; i++) {
			cin >> a[i];
		}
		for(i=0; i<n; i++) {
			cin >> b[i];
		}
		for(i=0; i<n; i++) {
			if(a[i] + b[n-1-i] > x) {
				break;
			}
		}
		cout << (i<n?"No":"Yes") << endl;
	}
}
