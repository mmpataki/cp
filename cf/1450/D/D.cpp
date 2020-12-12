#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L	__FUNCTION__ << ":" << __LINE__
#define X(x) { cout << F_AND_L << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << F_AND_L __VA_ARGS__ << endl;
#define PC(a) { cout << F_AND_L << " " << #a << "=["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << F_AND_L << " " << #a << "=["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }
#else
#define X(x)
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

#define rep(i, s, e) for(int i=s; i<e; i++)
#define reps(i, s, e, stp) for(int i=s; i<e; i+=stp)
#define per(i, s, e) for(int i=e; i>=0; i--)
#define pers(i, s, e, stp) for(int i=e; i>=0; i+=stp)
#define F(i, n) for(int i=0; i<n; i++)
#define R(i, n) for(int i=n-1; i>=0; i--)

int T[3*100000+1];
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		int hasOne=0,uniq=1;
		memset(T, 0, sizeof(int) * (n+1));
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] == 1) hasOne=1;
			if(a[i]>n) uniq=0;
			else T[a[i]]=1;
		}
		for(int i=1; i <= n; i++) if(T[i]!=1) {uniq=0; break;}
		int l=0, r=n-1;
		vector<int> ans;
		int vio=0;
		ans.push_back(hasOne);
		for(int i=1; i<n; i++) {
			if(l>r) continue;
			if(vio) {ans.push_back(0); continue;}
			if(a[l] != i && a[r] != i) {
				ans.push_back(0);
				vio=1;
			} else {
				if(a[l] == i && a[r] == i) {
					ans.push_back(0);
					vio=1;
				} else {
					ans.push_back(1);
					if(a[l] == i)l++;
					if(a[r] == i)r--;
				}
			}
		}
		ans.push_back(uniq);
		PC(ans)
		for(int i=n-1; i>=0; i--) {
			cout<<ans[i];
		}
		cout<<endl;
	}
}
