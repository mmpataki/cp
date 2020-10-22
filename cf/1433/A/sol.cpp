#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) printf( #x ": ", x)

int main(int argc, char ** argv) {
	
	int t;
	cin >> t;
	
	while(t--) {
		int s;
		cin >> s;
		int len = 0, x = s;
		while(x) { x /= 10; len++; }
		cout << (((s % 10) + -1) * 10 + ((len * (len+1)) / 2)) << endl;
	}
	
}
