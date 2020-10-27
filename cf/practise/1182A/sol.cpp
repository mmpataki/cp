#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#ifdef LOCAL
#define D(x) printf( #x ": ", x)
#else
#define D(x) 
#endif

int main(int argc, char ** argv) {
	
	int t;
	cin >> t;
	
	if(t % 2) {
		cout << "0\n";
	} else {
		cout << (1 << (t/2)) << endl;
	}
}
