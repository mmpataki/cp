#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#ifndef ONLINE_JUDGE
#define F_AND_L	<< __FUNCTION__ << ":" << __LINE__
#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << F_AND_L << __VA_ARGS__ << endl;
#define PC(a) { cout << F_AND_L << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << F_AND_L << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }
#else
#define X(x)
#define D(x)
#define S(...)
#define PC(a)
#define PA(a,s,l)
#endif

template <typename T>
class MinMaxStack {
	//          value   min  max
	vector<pair<T, pair<int, int>>> v;
public:
	T pop() {
		T t = v[v.size()-1].first;
		v.pop_back();
		return t;
	}
	void push(T t) {
		v.push_back(make_pair(t, make_pair(0, 0)));
		if(v.size() > 1) {
			int i = v.size() - 1;
			int last_min_i = v[i - 1].second.first;
			v[i].second.first = (t < v[last_min_i].first) ?  i : last_min_i;
			int last_max_i = v[i - 1].second.second;
			v[i].second.second = (t > v[last_max_i].first) ? i : last_max_i;
		}
	}
	T min() {
		return v[v[v.size() - 1].second.first].first;
	}
	T max() {
		return v[v[v.size() - 1].second.second].first;
	}
};


int main(int argc, char ** argv) {
	MinMaxStack<int> mms;
	
	mms.push(1);
	mms.push(3);
	mms.push(2);
	assert(mms.max() == 3);
	assert(mms.min() == 1);
	mms.pop();
	mms.pop();
	mms.push(0);
	assert(mms.min() == 0);
	assert(mms.max() == 1);
}
