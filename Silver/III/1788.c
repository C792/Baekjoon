#include <cstdio>
#include <cmath>
#include <algorithm>
const int re = 1'000'000'000;
int f[1000001];

int neg(int N) {
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= N; i++) {
		f[i] = (f[i - 2] - f[i - 1]) % re;
	}
	return f[N];
}

int pos(int N) {
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= N; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % re;
	}
	return f[N];
}

int main() {
	int n;
	scanf("%d",&n);
	int ans = (n >= 0) ? pos(n) : neg(-n);

	if (ans < 0) printf("-1\n");
	else if (ans == 0) printf("0\n");
	else printf("1\n");
	printf("%d",abs(ans));
}