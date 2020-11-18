#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) printf( #x ": ", x)

int main(int argc, char ** argv) {
	
	int k, a[12];
	cin >>k;
	for(int i=0; i<12; i++) {
		cin >> a[i];
	}
	sort(a, a+12);
	int j=11, ans=0;
	while(k > 0 && j >= 0) {
		ans++;
		k -= a[j--];
	}
	if(k > 0)
		ans = -1;
	cout << ans << endl;
}
