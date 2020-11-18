#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define MOD 998244353
#define X(c) ((((c % MOD) * (c % MOD + 1)) / 2) % MOD)

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	lint a, b, c;
	cin >> a >> b >> c;
	
	cout << ((((X(a) * X(b)) % MOD) * X(c)) % MOD) << endl;
}
