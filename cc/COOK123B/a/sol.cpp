#include <bits/stdc++.h>
using namespace std;

char b[100001];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cin >> b;
		int T[256] = {0};
		for(int i=0; i<n; i++)
			T[(int)b[i]]++;
		cout << (T[(int)b[n-1]] > 1 ? "YES" : "NO") << endl;
	}
}
