#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, v;
	cin >> n >> v;
	
	if(v > n) {
		cout << n - 1 << endl;
	} else {
		int x = n - v;
		cout << ((v-1) + (x * (x + 1) / 2)) << '\n';
	}	
}
