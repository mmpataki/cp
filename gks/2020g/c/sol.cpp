#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	int p = 1;
	while(t--)  {
		int w, n;
		cin >> w >> n;

		long long int v[w], sum=0;
		for(int i=0; i<w; i++) {
			cin >> v[i];
			sum += v[i];//(v[i] > (n - v[i])) ? (n - v[i]) : v[i];
		}

		long long mean = sum / w;
		cout << "mean: " << mean << endl;
		sum = 0;
		for(int i=0; i<w; i++) {
			if(mean > v[i]) {
				if(mean - v[i] < (v[i] + (n - mean))) {
					sum += mean - v[i];
				} else {
					sum += v[i] + (n - mean);
				}
			} else {
				if(v[i] - mean < (mean + (n - v[i]))) {
					sum += v[i] - mean;
				} else {
					sum += mean + (n - v[i]);
				}
			}
		}
		cout << "Case #" << p++ << ": " << sum << endl;
	}
}

/**
variance
------------------|
                  |----
		  |--------
		  |--
	----------|
 */
