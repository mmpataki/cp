#include <bits/stdc++.h>
using namespace std;

int main() {

	int ans=0, n;

#ifndef ONLINE_JUDGE
for(n=1; n<1001; n++) {
#else
	cin >> n;
#endif
	ans = (n==1 ? 3 : 1);
#ifndef ONLINE_JUDGE
	int p = n*ans+1, flag=0;
	for(int j = 2; j<p; j++) {
		if(p % j == 0) {
			flag = 1;
			break;
		}
	}
}
#else
	cout << ans << endl;
#endif
}
