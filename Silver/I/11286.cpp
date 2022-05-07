//11286 : 절댓값 힙
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> positive;
priority_queue<int> negative;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
	cin >> n;
	while(n--) {
		cin >> x;
		if (!x)	{
			if (positive.empty() && negative.empty()) cout << "0\n";
			else if (positive.empty()) {
				cout << negative.top() << '\n';
				negative.pop();
			}
			else if (negative.empty()) {
				cout << positive.top() << '\n';
				positive.pop();
			}
			else if (positive.top() < -negative.top()) {
				cout << positive.top() << '\n';
				positive.pop();
			}
			else {
				cout << negative.top() << '\n';
				negative.pop();
			}
		}
		else if (x > 0) positive.push(x);
		else negative.push(x);
	}
	return 0;
}