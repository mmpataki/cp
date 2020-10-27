#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#ifdef LOCAL
#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl; }
#else
#define D(x) {}
#endif

int main(int argc, char ** argv) {
	
	int n, t, mx=0;
	cin >> n;
	int a[101] = {0};
	for(int i=0; i<n; i++) {
		cin >> t;
		a[t]++;
		mx=max(t, mx);
	}
	int j=1, colors=0;
	D(mx)
	while(j <= mx) {
		if(a[j]) {
			D(j)
			colors++;
			for(int i=j; i<=mx; i+=j) {
				a[i] = 0;
			}
		}
		j++;
	}
	cout << colors << endl;
}
