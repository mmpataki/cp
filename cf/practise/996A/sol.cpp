#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) printf( #x ": ", x)

int main(int argc, char ** argv) {
	
	lint n;
	cin >> n;
	
	lint s=0;
	
	int d[] = {1, 5, 10, 20, 100};
	
	for(int i=4; i>=0; i--) {
		s += (n / d[i]);
		n = n % d[i];
	}
	
	cout << s << endl;
	
}
