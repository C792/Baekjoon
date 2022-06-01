//9204 : 체스
#include<iostream>

int juldaegap(int a) {
	return a > 0 ? a : -a;
}
int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		char s1, s2;
		int a = 0, b = 0, c = 0, d = 0;
		scanf(" %c %d %c %d", &s1, &b, &s2, &d);
		a = s1 - 'A' + 1;
		c = s2 - 'A' + 1;
		int x1 = (a + b + c - d), x2 = (a - b + c + d), y1 = (b - a + c + d), y2 = (a + b - c + d), x, y;
		//if (x1 > 0 && y1 > 0) {
			x = x1 / 2;
			y = y1 / 2;
		//}
		//else {
		//	x = x2 / 2;
		//	y = y2 / 2;
		//}
		x += 'A' - 1;
		if (x1 % 2 || y1 % 2) {
			printf("Impossible\n");
			continue;
		}
		else if (a == c && b == d) {
			printf("0 %c %d\n", a + 'A' - 1, b);
		}
		else if (juldaegap(a - c) == juldaegap(b - d)) {
			printf("1 %c %d %c %d\n", a + 'A' - 1, b, c + 'A' - 1, d);
		}
		else printf("2 %c %d %c %d %c %d\n", a + 'A' - 1, b, x, y + 1, c + 'A' - 1, d);						

		x = x2 / 2;
		y = y2 / 2;
		x += 'A' - 1;

		if (a == c && b == d) {
			printf("0 %c %d\n", a + 'A' - 1, b);
		}
		else if (juldaegap(a - c) == juldaegap(b - d)) {
			printf("1 %c %d %c %d\n", a + 'A' - 1, b, c + 'A' - 1, d);
		}
		else printf("2 %c %d %c %d %c %d\n", a + 'A' - 1, b, x, y + 1, c + 'A' - 1, d);
	}
}