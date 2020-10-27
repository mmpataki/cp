#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#ifdef LOCAL
#define D(x) printf( #x ": ", x)
#else
#define D(x) 
#endif

int main(int argc, char ** argv) {
	
	int n;
	cin >>n;
	
	int a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	int t[n];
	t[0] = 0;
	if(n > 1)
		t[1] = abs(a[1]-a[0]);
	for(int i=2; i<n; i++) {
		int s1 = t[i-1] + abs(a[i] - a[i-1]);
		int s2 = t[i-2] + abs(a[i] - a[i-2]);
		t[i] = min(s1, s2);
	}
	
	cout << t[n-1] << endl;
	
}
