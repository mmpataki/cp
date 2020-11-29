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

/**
 * binary search.
 * 	T : type of the index (int, long, long long)
 *  F : function to reduce the search space
 * 			return:
 * 				< 0 search on left side
 * 				> 0 search on right side
 * 				= 0 search finished
 */
template<typename T, typename Func>
T bsearch(T start, T end, Func fun, bool debug=false) {
	T mid = start;
	while(true) {
		mid = (end - start) / 2 + start;
		if(debug) {
			cout << "start: " << start << "mid: " << mid << "end: " << end << endl;
		}
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
	
	ll t;
	cin >> t;

	auto bsfun = [t](ll s, ll m, ll e) {
		return (t+1) - (((m + 1) * m) / 2);
	};
	cout << (t + 1 - bsearch(1ll, (ll)ceil(sqrt(t+1)) * 2, bsfun)) << endl;
}
