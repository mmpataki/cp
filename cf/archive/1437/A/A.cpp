#include <bits/stdc++.h>
using namespace std;
	
typedef long long int lint;
	
#ifndef ONLINE_JUDGE
#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl; }
#else
#define D(x) 
#endif
	
int main(int argc, char ** argv) {
	
	int t;
	cin >> t;
	
	while(t--) {
		
		lint l, r;
		cin >> l >> r;
		
		cout << (((r - l + 1) < l) ? "YES" : "NO") << endl;
		
	}
	
}