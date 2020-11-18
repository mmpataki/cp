#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

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

lint n, k, ans=0;
lint a[10][10];
lint dest, dtimes;

int visited[10] = {0,0,0,0,0, 0,0,0,0,0};
int soli=0;

void dfs(int cur, int cost, int len) {
	if(visited[cur])
		return;
	if(len == n-1) {
		if((cost + a[cur][0]) == k) {
			ans++;
		}
		return;
	}
	visited[cur] = 1;
	for(int i=0; i<n; i++) {
		dfs(i, cost + a[cur][i], len+1);
	}
	visited[cur] = 0;
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	#ifdef MMPATAKI_TEST

	n=8, k=-1;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) a[i][j]=rand() % 100;

	#else
	
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}

	#endif
	
	dfs(0, 0, 0);
	cout << ans << endl;
}
