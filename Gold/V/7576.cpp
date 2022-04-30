//7576 : 토마토(2차원)
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct ls {
	int x;
	int y;
	int num;
};

queue<ls> q;

int n, m, ans, in[1000][1000], chk[1000][1000], cnt;

void tomato(int x, int y, int num) {
	static int count = 0;
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) cout << chk[i][j] << ' ';
	//	cout << endl;
	//}
	if (!chk[x][y]) {
		q.push({ x, y, num + 1 });
		cnt++;
		chk[x][y]++;
		//cout << "!";
	}
	//cout << ++count << "---------------------\n" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> in[i][j];
		if (in[i][j] == 1) {
			q.push({ i, j, 0 });
			chk[i][j]++;
			cnt++;
		}
		if (in[i][j] == -1) {
			chk[i][j]++;
			cnt++;
		}
	}

	while (!q.empty()) {
		int X = q.front().x, Y = q.front().y;
		ans = q.front().num;
		q.pop();
		tomato(X, Y - 1, ans);
		tomato(X, Y + 1, ans);
		tomato(X - 1, Y, ans);
		tomato(X + 1, Y, ans);
	}
	//cout << cnt << ' ' << ans << endl;
	if (cnt < n * m) cout << -1;
	else cout << ans;
}