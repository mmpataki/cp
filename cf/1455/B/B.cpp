#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L __FUNCTION__ << ":" << __LINE__
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


template<typename T, typename Func>
T bsearch(T start, T end, Func fun) {
	T mid = start;
	while(true) {
		mid = (end - start) / 2 + start;
		T ret = fun(start, mid, end);
		if(ret == 0 || mid == start || mid == end) {
			break;
		}
		if(ret < 0) { end = mid; } 
		else if (ret > 0) { start = mid; }
	}
	return mid;
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		ll x;
		cin >> x;

		auto bfun = [x](int s, int m, int e) {
			S(D(s) D(m) D(e))
			return x - ((m * (m+1)) / 2);
		};

		ll n = bsearch(0ll, x, bfun);
		X(x)
		X(n)
		ll sum = n * (n + 1) / 2;
		X(sum)
		if(sum == x) {
			cout << n << endl;
		} else {
			ll d=n;
			if(sum < x) {
				d=n; 
				sum+=(++n);
			}

			X(sum)
			cout << min(n+(sum-x), (x-d)) << endl;
		}
	}
	
}
