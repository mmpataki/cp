#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) printf( #x ": ", x)
#define hasKey(m, key) (m.find(key) != m.end())

int main(int argc, char ** argv) {
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, j=0;
		cin >> n;
		
		lint a[n], bg[2], bd[2];
		for(int i=0; i<n; i++) {
			cin >> a[i];
			if(j == 0) {
				bg[0] = a[i];
				bd[0] = i;
				j++;
			} else if(j == 1 && bg[0] != a[i]) {
				bg[j] = a[i];
				bd[j] = i;
				j++;
			}
		}
		
		if(j < 2) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			for(int i=0; i<n; i++) {
				if(bd[0] != i && bd[1] != i)
					cout << (i+1) << " " << (a[i] == bg[0] ? bd[1]+1 : bd[0]+1) << endl;
			}
			cout << (bd[0]+1) << " " << (bd[1]+1) << endl;
		}
	}
}
