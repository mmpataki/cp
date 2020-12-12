#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifdef DEBUG
#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << __FUNCTION__ << " " __VA_ARGS__ << endl;
#define PC(a) { cout << __FUNCTION__ << " " << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << __FUNCTION__ << " " << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }   
#else
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		char a[n][m+1];
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		int filters[4][3][2] = {
			{{0, -1}, {0, 0}, {1, 0}},
			{{0, 1}, {0, 0}, {1, 0}},
			{{0, 0}, {1, 0}, {1, -1}},
			{{0, 0}, {1, 0}, {1, 1}}
		};
		int sol[3*n*m][3][2], soli=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j] == '1') {
					// select a filter
					int filt = -1, tmp_match=0;
					for(int k=0; k<4; k++) {
						int match=0;		
						for(int d=0; d<3; d++) {
							int ii=i+filters[k][d][0];
							int jj=j+filters[k][d][1];
							if(ii >= n || jj >= m || ii < 0 || jj < 0) {
								match=-100;
								break;
							}
							match += a[ii][jj] - '0';
						}
						if(match > tmp_match) {
							tmp_match = match;
							filt = k;
						}
					}
					X(filt)
					if(filt==-1) {
						continue;
					}
					// apply the filter
					for(int k=0; k<3; k++) {
						int ii=i+filters[filt][k][0];
						int jj=j+filters[filt][k][1];
						
						sol[soli][k][0] = ii;
						sol[soli][k][1] = jj;
						a[ii][jj]=a[ii][jj]=='1'?'0':'1';
					}
					soli++;
				}
			}
		}
		// last line
		int lfilters[][][] = {
			{{0,0}, {0,1}, {-1,1}},
			{{-1,1}, {0,1}, {0,2}}
		}
		for(int j=0, i=n-1; j<m; j++) {
			if(a[i][j] == '1') {
				for(int k=0; k<2; k++) {
					for(int d=0; d<3; d++) {
						int ii=i+lfilters[k][d][0];
						int jj=j+lfilters[k][d][1];
						if(jj >= n) break;
						sol[soli][d][0] = ii;
						sol[soli][d][1] = jj;
						a[ii][jj] = a[ii][jj] == '1' ? '0' : '1';
					}
				}
				soli++;
			}
		}
		PA(a, 0, n)
		cout << soli << endl;
		for(int i=0; i<soli; i++) {
			cout << sol[0][0] << sol[0][1] << sol[1][0] << sol[1][1] << sol[2][0] << sol[2][1] << endl;
		}
	}
	
}













