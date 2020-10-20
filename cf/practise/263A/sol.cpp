#include <bits/stdc++.h>
using namespace std;

int main(int argc, char ** argv) {
	
	int r, c;
	char b[2];
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			cin >> b;
			if(b[0] == '1') {
				r = i;
				c = j;
				break;
			}
		}
	}
	
	cout << (abs(r-2) + abs(c-2)) << endl;
	return 0;
}
