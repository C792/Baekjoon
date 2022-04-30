//7569 : 토마토(3차원)
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct ls {
	int x;
	int y;
	int z;
	int num;
};

queue<ls> q;

int n, m, l, ans, in[100][100][100], chk[100][100][100], cnt;

void tomato(int x, int y, int z, int num) {
	if (x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= l) return;
	if (!chk[x][y][z]) {
		q.push({ x, y, z, num + 1 });
		cnt++;
		chk[x][y][z]++;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n >> l;

	for (int k = 0; k < l; k++) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> in[i][j][k];
		if (in[i][j][k] == 1) {
			q.push({ i, j, k, 0 });
			chk[i][j][k]++;
			cnt++;
		}
		if (in[i][j][k] == -1) {
			chk[i][j][k]++;
			cnt++;
		}
	}
	while (!q.empty()) {
		int X = q.front().x, Y = q.front().y, Z = q.front().z;
		ans = q.front().num;
		q.pop();
		tomato(X, Y - 1, Z, ans);
		tomato(X, Y + 1, Z, ans);
		tomato(X - 1, Y, Z, ans);
		tomato(X + 1, Y, Z, ans);
		tomato(X, Y, Z + 1, ans);
		tomato(X, Y, Z - 1, ans);
	}
	if (cnt < n * m * l) cout << -1;
	else cout << ans;
}