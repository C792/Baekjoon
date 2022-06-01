//10026 : 적록색약
#include<iostream>
#include<string>

using namespace std;

int map[101][101], rgmap[101][101],
cnt, rgcnt,
dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool chk[101][101], rgchk[101][101];
void dfs(int x, int y) {
	chk[x][y] = 1;
	for (int i = 0; i < 4; i++)
		if (map[x][y] == map[x + dx[i]][y + dy[i]] && !chk[x + dx[i]][y + dy[i]])
			dfs(x + dx[i], y + dy[i]);
}
void rgdfs(int x, int y) {
	rgchk[x][y] = 1;
	for (int i = 0; i < 4; i++)
		if (rgmap[x][y] == rgmap[x + dx[i]][y + dy[i]] && !rgchk[x + dx[i]][y + dy[i]])
			rgdfs(x + dx[i], y + dy[i]);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	string in;
	for (int i = 0; i < N; i++) {
		cin >> in;
		for (int j = 0; j < N; j++) {
			map[i][j] = in[j];
			if (in[j]=='G') rgmap[i][j] = 'R';
			else rgmap[i][j] = in[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!chk[i][j]) {
				dfs(i, j);
				cnt++;
			}
			if (!rgchk[i][j]) {
				rgdfs(i, j);
				rgcnt++;
			}
		}
	}
	cout << cnt << ' ' << rgcnt;
}