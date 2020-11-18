#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}

char s[100001];

int count(int n, char seed) {
	int x=-2, ret=0, zlen=0;
	for(int i=0; i<n; i++) {
		D(s[i]) D(seed)
		if(s[i] != seed) {
			if(x == (i-1)) {
				zlen++;
				ret--;
				x=i;
				i++;
			} else {
				ret++;
				x=i;
			}
		}
		seed = (seed == '0' ? '1' : '0');
	}
	D(ret) D(zlen)
	return ret*2+zlen;
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		cin >> s;
		int z = count(n, '0');
		int o = count(n, '1');
		cout << (min(z, o)) << endl;
	}
	
}
