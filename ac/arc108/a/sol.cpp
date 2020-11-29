#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << __FUNCTION__ << " " __VA_ARGS__ << endl;
#define PC(a) { cout << __FUNCTION__ << " " << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << __FUNCTION__ << " " << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }   
#else
#define X(x)
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

int TEST(ll x, ll y, ll p, ll s) {
    return (x > 0 && y > 0 && (x+y==s) && (x * y == p));
}
int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	double s, p;
    cin >> s >> p;

    if(s * s < 4 * p) {
        cout << "NO" << endl;
        return 0;
    }

    double sol1 = (s + sqrt(s * s - (4 * p))) / 2;
    double sol2 = (s - sqrt(s * s - (4 * p))) / 2;

    ll ls1 = sol1;
    ll ls2 = sol2;

    if(TEST(ls1, (s-ls1), p, s) || TEST(ls2, (s-ls2), p, s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
