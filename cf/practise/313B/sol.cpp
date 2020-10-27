#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#ifdef LOCAL
#define D(x) printf( #x ": ", x)
#else
#define D(x) 
#endif

int main(int argc, char ** argv) {
	
	char s[100001];
	cin >> s;
	
	char p = s[0];
	int a[100001] = {0}, j=0;
	for(int i=0; s[i]; i++) {
		if(p != s[i]) {
			j++;
			p = s[i];
		}
		a[i] = j;
	}
	
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++) {
		int l, r;
		cin >> l >> r;
		cout << (a[r] - a[l]) << endl;
	}
	
}
