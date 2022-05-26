//2696 : 중앙값 구하기
#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		priority_queue<int> l;
		priority_queue<int, vector<int>, greater<int>> r;
		vector<int> mid;
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
			if (!(tc % 2)) {
				if (!l.empty() && !r.empty()) {
					if (l.top() < r.top()) mid.push_back(l.top());
					else mid.push_back(r.top());
				}
				else mid.push_back(l.top());
			}
		}
		cout << mid.size() << '\n';
		for (int i = 0; i < mid.size(); i++) {
			cout << mid[i] << ' ';
		}
		cout << '\n';
		mid.clear();
	}
}