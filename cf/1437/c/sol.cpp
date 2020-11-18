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
		int b=0, p, x;
		cin >> x;
		vector<int> lh;
		int h=0;
		lh.push_back(1);
		for (int i = 0; i < n-1; i++)
		{
			cin >> x;
			if(i && p > x)
				lh.push_back(b);
				if(!--lh[h]) {
					h++;
				}
				b=-1;
			}
			b++;
			p = x;
		}
		int h;
		
	}
	
}
