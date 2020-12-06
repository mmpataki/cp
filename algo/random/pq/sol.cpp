#include <bits/stdc++.h>
using namespace std;

#define F_AND_L	__FUNCTION__ << ":" << __LINE__
#define X(x) { cout << F_AND_L <<  "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << F_AND_L __VA_ARGS__ << endl;
#define PC(a) { cout << F_AND_L << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << F_AND_L << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }



#define LEF(x) (x << 1)
#define RIT(x) ((x << 1) + 1)
#define PAR(x) (x >> 1)

void m_heapify(int min, int *a, int n, int i) {
	int l = LEF(i);
	int r = RIT(i);
	int pick = i;
	if(min) {
		if(l <= n && a[l] < a[pick]) pick = l;
		if(r <= n && a[pick] > a[r]) pick = r;
	} else {
		if(l <= n && a[l] > a[pick]) pick = l;
		if(r <= n && a[pick] < a[r]) pick = r;
	}
	
	if(i != pick) {
		swap(a[i], a[pick]);
		m_heapify(min, a, n, pick);
	}
}

void make_m_heap(int min, int *a, int siz) {
	for(int i = ceil(siz / 2); i > 0; i--) {
		m_heapify(min, a, siz, i);
	}
}

void make_min_heap(int *a, int siz) {
	make_m_heap(1, a, siz);
}

void make_max_heap(int *a, int siz) {
	make_m_heap(0, a, siz);
}

int extract_m(int min, int *a, int &n) {
	int ret = a[1];
	n--;
	if(n - 1 != 0) {
		a[1] = a[n + 1];
		m_heapify(min, a, n, 1);
	}
	return ret;
}

int extract_min(int *a, int &n) {
	return extract_m(1, a, n);
}

int extract_max(int *a, int &n) {
	return extract_m(0, a, n);
}

void propagate_up(int *a, int idx) {
	while(PAR(idx) >= 1 && a[PAR(idx)] < a[idx]) {
		swap(a[idx], a[PAR(idx)]);
		idx = PAR(idx);
	}
}

void change_key(int min, int *a, int n, int idx, int delta) {
	a[idx] += delta;
	if(min) {
		if(delta < 0) {
			propagate_up(a, idx);
		} else {
			m_heapify(min, a, n, idx);
		}
	} else {
		if(delta < 0) {
			m_heapify(min, a, n, idx);
		} else {
			propagate_up(a, idx);
		}
	}
}

void increase_key(int min, int *a, int n, int idx, int delta) {
	change_key(min, a, n, idx, delta);
}

void decrease_key(int min, int *a, int n, int idx, int delta) {
	change_key(min, a, n, idx, -delta);
}

int main() {
	int a[] = {-1,0,1,2,3,4,5,6,7,8,9,10,11,12};
	int n1 = 14;
	make_max_heap(a, n1-1);
	for(int i=n1-2; i>=0; i--) {
		int ans = extract_max(a, n1);
		S(D(ans) D(i))
	}

	int b[] = {-1,0,1,2,3,4,5,6,7,8,9,10,11,12};
	int n2 = 14;
	make_min_heap(b, n2-1);
	for(int i=0; i<13; i++) {
		int ans = extract_min(b, n2);
		S(D(ans) D(i))
		if(ans != i) {
			cout << "fail";
			PA(a, 0, n1)
			return 0;
		}
	}

	int c[] = {-1,0,1,2,3,4,5,6,7,8,9,10,11,12};
	int n3 = 14;
	make_min_heap(c, n3-1);
	PA(c, 0, n3)
	extract_min(a, n3);
	PA(c, 0, n3)
	decrease_key(1, a, n3-1, 1, 1);
	PA(c, 0, n3)
	extract_min(a, n3);
	PA(c, 0, n3)

}