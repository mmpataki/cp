#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#ifndef ONLINE_JUDGE
#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl; }
#else
#define D(x) 
#endif

const int INF = INT_MAX;

int main(int argc, char ** argv) {
	
	int n, k;
	cin >> n >> k;
	
	int a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
		D(a[i])
	}
	
	int t[n];
	for(int i=0; i<n; i++) t[i] = INF;
	t[0] = 0;

	for(int i=1; i<n; i++) {
		for(int j=1; i-j>=0 && j<=k; j++) {
			D(t[i]) 
			int s = t[i-j] + abs(a[i-j] - a[i]);
			D(s)
			t[i] = min(t[i], s);
		}
		D(t[i])
	}
	
	cout << t[n-1] << endl;
}
