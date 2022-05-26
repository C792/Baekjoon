//1655 : 가운데를 말해요
#include<iostream>
#include<queue>

using namespace std;

priority_queue<int> l;
priority_queue<int, vector<int>, greater<int>> r;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int a;
		cin >> a;
		if (l.empty()) l.push(a);
		else if (r.empty()) r.push(a);
		else {
			l.push(a);
			while (l.top() > r.top()) {
				l.push(r.top());
				r.pop();
				r.push(l.top());
				l.pop();
			}
			while (l.size() - 1 > r.size()) {
				r.push(l.top());
				l.pop();
			}
		}
		if (!l.empty() && !r.empty()) {
			if (l.top() < r.top()) cout << l.top() << '\n';
			else cout << r.top() << '\n';
		}
		else cout << l.top() << '\n';
	}
}