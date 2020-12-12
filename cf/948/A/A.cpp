#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int R, C; cin >> R >> C;

	char b[R][C+1];
	for(int i=0; i<R; i++) cin >> b[i];

	for(int i = 0; i<R; i++)
		for(int j=0; j<C; j++)
			b[i][j] = (b[i][j] == '.') ? 'D' : b[i][j];

	#define CHECK(i, j) (i >= 0 && i < R && j >= 0 && j < C && b[i][j] == 'S')
	for(int i = 0; i<R; i++) {
		for(int j = 0; j<C; j++) {
			if(b[i][j] == 'W') {
				if(CHECK(i+1, j) || CHECK(i, j+1) || CHECK(i-1, j) || CHECK(i, j-1)) {
					cout << "No";
					return 0;
				}
			}
		}
	}

	cout << "Yes" << endl;
	for(int i = 0; i<R; i++) cout << b[i] << endl;
}
