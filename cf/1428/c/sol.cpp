#include <bits/stdc++.h>
using namespace std;
#define MOD (1000000000+9)

char s[200001], c[200001];

int main() {
	int t;
	cin>>t;
	while(t--) {
		char ch;
		int cur=-1;

		cin >> c;
		for(int i=0; ch=c[i]; i++) {
			s[++cur] = ch;
			if(cur==0)
				continue;
			if(s[cur]=='B')
				cur-=2;
		}
		cout << (cur + 1) << endl;
	}
}

