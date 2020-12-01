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

#define MOD ((ll)1e9+7)

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

vector<ll> fact;
void comp_fact(int n) {
	fact[0]=1;
	for(int i = 1; i <= n; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, pos;
	cin >> n >> x >> pos;

	int more=0, less=0;
	auto bfun = [pos, &less, &more](int s, int m, int e) {
		S(D(s) D(m) D(e))
		if(pos - m < 0) { more++; }
		else if (pos - m  > 0) { less++; }
		return pos - m;
	};

	bsearch(0, n, bfun);

	fact.resize(n+1);
	comp_fact(n);

	S(D(more) D(less))
	
	ll ans;
	if(more > (n - x)) { ans = 0; }
	else if(less > x) { ans = 0; }
	else {
		int lav = x - 1;
		int mav = n - x;
		S(D(lav) D(mav))
		ans = 1;
		if(more)
			ans *= (fact[mav] / ((fact[more] * fact[mav - more]) % MOD)) % MOD;
		if(less)
			ans *= (fact[lav] / ((fact[less] * fact[lav - less]) % MOD)) % MOD;
		int used = more + less + 1;
		int ss = n - used;
		ans *= (fact[ss] / ((fact[used] * fact[ss - used]) % MOD)) % MOD;
	}
	cout << ans << endl;
}
