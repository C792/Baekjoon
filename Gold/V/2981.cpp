#include <stdio.h>
#include <algorithm>
int gcd(int m, int n) {
	int a, b;
	a = (m > n) ? m : n;
	b = m + n - a;
	a %= b;
	if (!a) return b;
	else return gcd(a, b);
}
void div(int n) {
	int i, j = 0;
	for (i = 2; i * i <= n; i++) {
		if (!(n % i)) printf("%d ", i);
	}
	for (i--; i > 1; i--) {
		if (n / i == 1) continue;
		if (!(n % i) && i * i != n) printf("%d ", n / i);
	}
	printf("%d", n);
	return;
}
int a, in[110], s[110], min, l;
int main() {
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
		scanf("%d", &in[i]);
	std::sort(in, in + a);
	for (int i = 0; i < a - 1; i++)
		s[i] = in[i + 1] - in[i];
	l = s[0];
	for (int i = 1; i < a - 1; i++) {
		l = gcd(l, s[i]);
	}
	div(l);
	return 0;
}