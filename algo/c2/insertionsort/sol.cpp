#include <bits/stdc++.h>
using namespace std;

void isort(int n, int *a) {
	for(int i=1; i<n; i++) {
		int key = a[i];
		int j;
		for(j=i-1; j>=0 && a[j]>key; j--) {
			a[j+1] = a[j];
		}
		a[j] = key;
	}
}

int main(int argc, char ** argv) {
	for(int i=0; i<1000; i++) {
		int r = rand() % 10000;
		int a[r];
		for(int j=0; j<r; j++) {
			a[j] = rand() % 10000;
		}
		
		isort(r, a);
		
		for(int j=1; j<r; j++) {
			assert(a[j-1] <= a[j]);
		}
	}
}

