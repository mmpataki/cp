#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
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

void merge(int *a, int ps, int pl, int qs, int ql) {
	PA(a, ps, pl)
	PA(a, qs, ql)
	S(D(ps) D(pl) D(qs) D(ql))
	int x[pl + ql];
	int i=ps, j=qs, k=0;
	while(i < ps+pl && j < qs+ql) {
		x[k++] = a[i] < a[j] ? a[i++] : a[j++];
	}
	S(D(k))
	for( ; i<ps+pl; i++, k++) x[k] = a[i];
	for( ; j<qs+ql; j++, k++) x[k] = a[j];
	for(int l=0; l<k; l++) a[l+ps] = x[l];
}

void msort(int *a, int s, int len) {
	PA(a, s, len)
	// 1 or less elements
	if(len < 2) {
		return;
	}
	
	// 2 elements, compare
	if(len == 2) {
		if(a[s + 1] < a[s]) {
			swap(a[s + 1], a[s]);
		}
		return;
	}
	
	// recurse, make sure the last element is not in the array
	int mid = len / 2;
	msort(a, s, mid);
	msort(a, s + mid, len - mid);
	merge(a, s, mid, s + mid, len - mid);
}

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// debug tests
	int x[] = {3,2,1};
	PC(x)
	msort(x, 0, 3);
	PC(x)
	
	// random tests
	srand(10);
	#define N 10000
	
	for(int i=0; i<1000; i++) {
		int r = rand() % N;
		int a[r];
		
		for(int j=0; j<r; j++) {
			a[j] = rand() % N;
		}
		
		PC(a)
		msort(a, 0, r);
		PC(a)
		
		for(int j=1; j<r; j++) {
			assert(a[j-1] <= a[j]);
		}
	}
}
