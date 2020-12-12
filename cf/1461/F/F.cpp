#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L	__FUNCTION__ << ":" << __LINE__
#define X(x) { cerr << F_AND_L << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cerr << F_AND_L __VA_ARGS__ << endl;
#define PC(a) { cerr << F_AND_L << " " << #a << "=["; for(auto __xmmp: a) { cerr << __xmmp << " "; } cerr << "]" << endl; }   
#define PA(a,s,l) { cerr << F_AND_L << " " << #a << "=["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cerr << a[__xmmp] << " "; } cerr << "]" << endl; }
#else
#define X(x)
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

#define rep(i, s, e) for(int i=s; i<e; i++)
#define reps(i, s, e, stp) for(int i=s; i<e; i+=stp)
#define per(i, s, e) for(int i=e; i>=0; i--)
#define pers(i, s, e, stp) for(int i=e; i>=0; i+=stp)
#define F(i, n) for(int i=0; i<n; i++)
#define R(i, n) for(int i=n-1; i>=0; i--)

void solve(vector<int> &v, int i) {
	if(i >= v.size()) {
		return;
	}
	if(v[i-1] > 1 && v[i] > 1) {
		cout << v[i-1] << '*'
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	solve(v, 1);
}
