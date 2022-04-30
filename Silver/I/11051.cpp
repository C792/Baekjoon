//11051 : 이항 계수 2
#include <stdio.h>
int ncr[1010][1010];
int c(int n, int r) {
	if (ncr[n][r]) return ncr[n][r];
	if (r == 1) return ncr[n][r] = n;
	if (!r || r == n) return ncr[n][r] = 1;
	if (r > n) return ncr[n][r] = 0;
	else return ncr[n][r] = (c(n - 1, r) + c(n - 1, r - 1))%10007;
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", c(n, k));
}