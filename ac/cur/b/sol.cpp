#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int r[n];
	for(int i=0; i<n; i++) {
		cin >> r[i];
	}
	
	int c[n];
	c[0] = r[0];
	for(int i=1; i<n; i++) {
		cin >> c[i];
	}
	int t[][3] = {
		{1,2,1},
		{2,0,0},
		{1,0,0}
	};
	int x[n];
	
	int *cur = x;
	int *old = r;
	int *tmp;
	lint o[3] = {0,0,0};
	for(int i=0; i<n; i++) {
		o[r[i]]++;
	}
	for(int j=1; j<n; j++) {
		for(int i=0; i<n; i++) {
			if(!i) {
				cur[0] = c[j];
			} else {
				cur[i] = t[old[i]][cur[i-1]];
			}
			o[cur[i]]++;
			cout << cur[i] << " ";
		}
		tmp = old;
		old = cur;
		cur = tmp;
		cout << endl;
	}
	cout << o[0] << " " << o[1] << " " << o[2] << endl;
}
