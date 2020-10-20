#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(int argc, char ** argv) {
	
	char s[105];
	cin >> s;
	
	int l=0;
	char b[55];
	
	int len = strlen(s);
	
	for(int i=0; i<len; i+=2) {
		b[l++] = s[i];
	}
	
	sort(b, b+l);
	
	for(int i=0; i<l; i++) {
		if(i)
			cout << "+";
		cout << b[i];
	}
}
