#include <bits/stdc++.h>
using namespace std;

int main(int argc, char ** argv) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << 500000 << endl;
	for(int i=0; i<500000; i++)
		cout << (rand() % 3) << " ";
	for(int i=1; i<500000; i++)
		cout << (rand() % 3) << endl;
}
