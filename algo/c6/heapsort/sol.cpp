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

#define PAR(x) (x / 2)
#define LEF(x) (x * 2)
#define RIT(x) (x * 2 + 1) 

inline void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t ;
}

/* heapify bin-tree rooted at `i` in `a` */
void max_heapify(int *a, int i, int n) {
	
	if(i > n) {
		return;
	}
	
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
		max_heapify(a, largest, n);
	}
}

void heapify(int *a, int n) {
	for(int i=n/2; i>0; i--) {
		max_heapify(a, i, n);
	}
}

void hsort(int *a, int n) {
	
	// heapify
	heapify(a, n);
	
	// verify
	for(int i=n; i>1; i--) {
		assert(a[PAR(i)] >= a[i]);
	}
	
	// sort
	for(int i=n; i>0; i--) {
		swap(a[1], a[i]);
		PA(a, 1, n)
		max_heapify(a, 1, i - 1);
		PA(a, 1, n)
	}
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	const int N=10000;
	
	for(int i=0; i<N; i++) {
		int r = rand() % N;
		int a[r + 1];
		for(int j=1; j<=r; j++) {
			a[j] = rand() % N;
		}

		PA(a, 1, r);
		hsort(a, r);
		PA(a, 1, r);
		
		for(int j=2; j<=r; j++) {
			assert(a[j-1] <= a[j]);
		}
	}
}
