#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

#ifdef DEBUG
#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << __FUNCTION__ << ":" << __LINE__ << " " __VA_ARGS__ << endl;
#define PC(a) { cout << __FUNCTION__ << ":" << __LINE__ << " " << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << __FUNCTION__ << ":" << __LINE__ << " " << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }   
#else
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

#define LEF(i) (i * 2)
#define RIT(i) (i * 2 + 1)
#define PAR(i) (i / 2)

#define swap(x, y) { int t = x; x = y; y = t; }

void max_heapify(int *a, int n, int i) {
	if(i > n)
		return;
	int l = LEF(i);
	int r = RIT(i);
	int largest = i;
	if(l <= n && a[l] > a[i]) {
		largest = l;
	}
	if(r <= n && a[r] > a[largest]) {
		largest = r;
	}
	if(i != largest) {
		swap(a[i], a[largest]);
		max_heapify(a, n, largest);
	}
}

void heapify(int *a, int n) {
	for(int i = n/2; i > 0; i--) {
		max_heapify(a, n, i);
	}
}

int get_max(int *a, int n) {
	return a[1];
}

int extract_max(int *a, int n) {
	int mx = a[1];
	a[1] = a[n];
	max_heapify(a, --n, 1);
	return mx;
}

void increase_key(int *a, int n, int i, int k) {
	assert(k > a[i]);
	a[i] = k;
	while(i > 1 && a[PAR(i)] < a[i]) {
		swap(a[i], a[PAR(i)])
		i = PAR(i);
	}
}

void insert(int *a, int r, int n, int x) {
	a[++r] = INT_MIN;
	increase_key(a, n, r, x);
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	#define N 1000
	
	for(int t=0; t<N; t++) {
		int r = rand() % N + 1;
		int mx = r;
		int a[r + 1];
		
		for(int i=1; i<=r; i++) {
			a[i] = rand() % N;
		}
	
		// test heapify
		heapify(a, r);
		for(int i=2; i<=r; i++) {
			assert(a[PAR(i)] >= a[i]);
		}
	
		// test get_max
		assert(get_max(a, r) == a[1]);
	
		// test increase key
		for(int i=1; i<=r; i++) {
			increase_key(a, r, i, a[i] + (rand() % N) + 1);
			for(int j=2; j<=r; j++) {
				assert(a[PAR(j)] >= a[j]);
			}
		}
		
		// test extract max
		int last = INT_MAX;
		for(int i=1; i<=r; i++) {
			int cur = extract_max(a, r - i + 1);
			assert(cur <= last);
			last = cur;
		}
		
		// test insert
		r=0;
		for(int j=1; j<mx; j++) {
			int nw = rand() % N;
			insert(a, r, mx, nw);
			r++;
			int found=0;
			for(int i=2; i<=r; i++) {
				assert(a[PAR(i)] >= a[i]);
				if(a[i] == nw) found = 1;
			}
			assert(found || a[1] == nw);
		}
	}
}
