#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifdef DEBUG
#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << __FUNCTION__ << " " __VA_ARGS__ << endl;
#define PC(a) { cout << __FUNCTION__ << " " << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << __FUNCTION__ << " " << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }   
#else
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	int msum=0, sum, ans=0;
	for(int i=0; i<n; i++) {
		if(i<k) {
			msum += a[i];
		} else {
			sum = msum - a[i-k] + a[i];
			if(sum < msum) {
				msum = msum;
				ans=i-k+1;
			}
		}
	}
	cout << ans << endl;
}
