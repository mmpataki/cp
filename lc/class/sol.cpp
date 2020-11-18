#include <bits/stdc++.h>
using namespace std;

#define X(x) { cout << "[ " << #x << " : " << x << " ]" << endl;}
#define D(x) << "[ " << #x << " : " << x << " ] "
#define S(...) cout << __FUNCTION__ << " " __VA_ARGS__ << endl;
#define PC(a) { cout << __FUNCTION__ << " " << #a << ": ["; for(auto __xmmp: a) { cout << __xmmp << " "; } cout << "]" << endl; }   
#define PA(a,s,l) { cout << __FUNCTION__ << " " << #a << ": ["; for(int __xmmp=s; __xmmp<s+l; __xmmp++) { cout << a[__xmmp] << " "; } cout << "]" << endl; }

class Stack {
	int a[10];
	int tos=0;
public:
	void push(int i);
	int pop();
	Stack();
};

void Stack::push(int i) {
	a[tos++]=i;
}
int Stack::pop() {
	return a[--tos];
}
Stack::Stack() {
	tos=0;
}

int main(int argc, char ** argv) {
	Stack stk;
	stk.push(1);
	stk.push(2);
	cout << stk.pop() << stk.pop() << endl;
}
