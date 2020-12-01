#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L	__FUNCTION__ << ":" << __LINE__
#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << F_AND_L __VA_ARGS__ << endl;
#define PC(a) { cout << F_AND_L << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << F_AND_L << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }
#else
#define X(x)
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	vector<int> v, isSorted;

	while(t--) {
		int x, n;
		cin >> n >> x;

		v.resize(n);
		isSorted.resize(n);
		for(int i = 0; i < n; i++) { cin >> v[i]; }

		int flag=1;
		for(int i = n-1; i>0; i--) {
			if(flag && v[i] < v[i-1]) {
				flag = 0;
			}
			isSorted[i] = flag;
		}
		isSorted[0] = isSorted[1] == 0 ? 0 : v[0] <= v[1];


		int ans=0;
		for(int i = 0; i < n - 1; i++) {
			if(x < v[i] && !isSorted[i]) {
				++ans;
				swap(v[i], x);
			}
		}

		int sorted = true;
		for(int i = 0; i < n - 1; i++) {
			if(v[i] > v[i+1]) {
				sorted = false;
				break;
			}
		}

		PC(v)

		cout << (sorted ? ans : -1) << endl;
	}
}
