#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		for(int i=0; i<n/2; i++) {
			int x, y;
			cin >> x >> y;
			if(i)
				cout << " ";
			cout << (-y) << " " << (x);
		}
		cout << endl;
	}
	
}
