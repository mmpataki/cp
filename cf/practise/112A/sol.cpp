#include <bits/stdc++.h>
using namespace std;

int main(int argc, char ** argv) {
	
	char a[105], b[105];
	int i;
	cin >> a>> b;
	for(i=0; a[i]; i++) {
		a[i] = toupper(a[i]);
		b[i] = toupper(b[i]);
		if(a[i] == b[i])
			continue;
		if(a[i] < b[i])
			cout << "-1";
		else
			cout << "1";
		break;
	}
	if(a[i] == b[i])
		cout << "0";
	cout << endl;
}
