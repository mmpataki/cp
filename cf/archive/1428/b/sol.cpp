#include <bits/stdc++.h>
using namespace std;
#define MOD (1000000000+9)

int t[300000], s[300001];
int ret(char *s, int n, int i) {
	if(t[i] > 0)
		return 1;
	
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n >> s;
		
		for(int i=0; i<n; i++) t[i]=-1;

		for(int i=0; i<n; i++) {
			if(ret(s, n, i))
				c++;

		cout << c << endl;
	}
}

