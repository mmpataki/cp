#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define D(x) printf( #x ": ", x)

int main(int argc, char ** argv) {
	
	char s[105];
	cin >> s;
	
	string h = "hello";
	int cur = 0;
	
	for(int i=0; s[i]; i++) {
		if(s[i] == h[cur])
			cur++;
		if(!h[cur]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}
