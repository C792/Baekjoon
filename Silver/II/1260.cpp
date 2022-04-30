//1260 : DFS와 BFS
#include<iostream>
#include<queue>
using namespace std;

int n, m, v, mat[1001][1001], chk[1001];

void dfs(int v) {
    cout << v << ' ';
    chk[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (chk[i] == 1||!mat[v][i])continue;
        dfs(i);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    chk[v] = 0;
    while (!q.empty()) {
        v = q.front();
        cout << q.front() << ' ';
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (chk[i] == 0 || mat[v][i] == 0)
                continue;
            q.push(i);
            chk[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        mat[x][y] = mat[y][x] = 1;
    }
    dfs(v);
    cout << '\n';
    bfs(v);
}