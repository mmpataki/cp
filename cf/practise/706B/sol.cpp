#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#ifndef ONLINE_JUDGE
#define D(x) { cout << "[ " << #x << " : " << x << " ]"; }
#define DL(x) { cout << "[ " << #x << " : " << x << " ]\n"; }
#else
#define D(x) 
#endif

int main(int argc, char ** argv) {
	
	int n;
	cin >> n;
	
	int a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	sort(a, a+n);
	
	int q, x;
	cin >> q;
	
	for(int i=0; i<q; i++) {
		cin >> x;
		auto d = upper_bound(a, a+n, x);
        int indx = distance(a, d);
		cout << (indx) << endl;
	}
}
