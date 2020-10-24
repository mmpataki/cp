#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#define MOD (1e9 + 7)
#define D(x) { cout << "[ " << #x << " : " << x << " ]" << endl; }

int main(int argc, char ** argv) {
	
	int h, w;
	cin >> h >> w;
	
	int r[h], c[w], zeros=0, fc=0;
	for(int i=0; i<h; i++) {
		cin >> r[i];
		if(r[i] == 0) {
			zeros++;
		}
	}
	for(int i=0; i<w; i++) {
		cin >> c[i];
		if(c[i] == 0) {
			zeros++;
		}
	}
	
	zeros -= (!r[0] && !c[0]);
	
	for(int i=0; i<r; i++) {
		if(
	
	
	D(fc) D(zeros);
}
