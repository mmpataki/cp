#include <bits/stdc++.h>
using namespace std;

int match(string s, int k, string m) {
	int i;
	for(i=0; i<m.length() && i+k < s.length(); i++) {
		if(s[i+k] != m[i])
			return 0;
	}
	if(i == m.length())
		return m.length();
	return -1;
}

int main() {
	int t; cin >> t;
	int p = 1;
	while(t--)  {
		string ds;
		cin >> ds;
		vector<int> sv, kv;
		for(int i=0; i<ds.length(); i++) {
			int k = match(ds, i, "KICK");
			int s = match(ds, i, "START");
			if(k == 4)
				kv.push_back(i);
			else if(s == 5)
				sv.push_back(i);
		}

#ifdef MPATDEBUG
for(int i=0 ; i<sv.size(); i++)
	cout << " : " << sv[i];
cout << endl;
for(int i=0 ; i<kv.size(); i++)
	cout << " : " << kv[i];
cout << endl;
#endif

		int k = 0, s = 0, sum = 0;
		while(k < kv.size()) {
			while(s < sv.size() && sv[s] < kv[k])
				s++;
			if(s >= sv.size())
				break;
			sum += sv.size() - s;
			k++;
		}
		cout << "Case #" << p++ << ": " << sum << endl;
	}
}

