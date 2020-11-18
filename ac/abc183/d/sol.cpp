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

struct Interval {
	int start;
	int end;
	lint lit;
};

bool compare(Interval i1, Interval i2) {
	return i1.start < i2.start;
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	lint w;
	
	vector<Interval> p;
	
	cin >> n >> w;
	p.resize(n);
	
	for(int i=0; i<n; i++) {
		cin >> p[i].start >> p[i].end >> p[i].lit;
	}
	
	sort(p.begin(), p.end(), compare);
	
	lint curCap = 0;
	
	for(int i=0; i<n; i++) {
		if(
	}
}
