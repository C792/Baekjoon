//1074 : Z
#include<iostream>
using namespace std;
int bil[16];
int bi(int a) {
	if (bil[a]) return bil[a];
	int n = a, ans = 1;
	while (n--) ans *= 2;
	return bil[a] = ans;
}

int z(int x, int y, int n) {
	if (n == 1) return y * 2 + x;
	int l = bi(n - 1);
	int x1 = x / l, y1 = y / l, x2 = x % l, y2 = y % l;
	return z(x2, y2, n - 1) + l * l * y1 * 2 + l * l * x1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, r, c;
	cin >> n >> r >> c;
	cout << z(c, r, n);
}