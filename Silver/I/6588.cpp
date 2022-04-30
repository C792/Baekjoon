//6588 : 골드바흐의 추측
#include <stdio.h>
int s[1000001];
int is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (!(n % i)) return 0;
	}
	return 1;
}
void primels(int a) {
    for (int i = 2; i < a + 1; i++) {
        s[i] = i;
        for (int j = 2; j * j <= i; j++) if (!(i % j)) s[i] = 0;
    }
    return;
}
int main() {
	primels(500000);
	int a = 1;
	while (a) {
		scanf("%d", &a);
		for (int i = 0; s[i] < a; i++) {
			int b = a - s[i];
			if (is_prime(b)) {
				printf("%d = %d + %d\n", a, s[i], b);
				break;
			}
		}
	}
}