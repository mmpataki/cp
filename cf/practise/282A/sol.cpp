#include <bits/stdc++.h>
using namespace std;

int main(int argc, char ** argv) {
	
	int t, c = 0;
	cin >> t;
	
	while(t--) {
		char x[4];
		cin >> x;
		if(x[0] == '+' || x[2] == '+') {
			c++;
		} else if(x[0] == '-' || x[2] == '-') {
			c--;
		}
	}
	
	cout << c << endl;
	
}

