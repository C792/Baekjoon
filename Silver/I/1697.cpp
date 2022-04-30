//1697 : 숨바꼭질
#include<iostream>
#include<queue>

using namespace std;

bool chk[100000];
bool v(int n) {
	if (n < 0 || n > 100000 || chk[n]) return 0;
	return 1;
}

int main() {
	int x, y, ans = 0;
	cin >> x >> y;
	queue<pair<int, int>> b;
	b.push({ x, 0 });
	while (!b.empty()) {
		int f = b.front().first, t = b.front().second;
		b.pop();
		if (f == y) {
			ans = t;
			break;
		}
		if (v(f - 1)) {
			chk[f - 1] = true;
			b.push({ f - 1, t + 1 });
		}
		if (v(f + 1)) {
			chk[f + 1] = true;
			b.push({ f + 1, t + 1 });
		}
		if (v(f * 2)) {
			chk[f * 2] = true;
			b.push({ f * 2, t + 1 });
		}
	}
	cout << ans;
}