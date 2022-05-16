//2630 : 색종이 만들기
#include <iostream>

void check(int n, int i) {

}

int z(int x, int y, int n) {
	if (n == 1) return y * 2 + x;
	int l = 1 << (n - 1);
	int x1 = x / l, y1 = y / l, x2 = x % l, y2 = y % l;
	return z(x2, y2, n - 1) + l * l * y1 * 2 + l * l * x1;
}

using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
}