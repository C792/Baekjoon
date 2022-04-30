//17425 : 약수의 합
#include <stdio.h>
typedef long long ll;
ll a[1000001];
int main() {
	int b;
	scanf("%d", &b);
	for (ll i = 1LL; i < 1000001LL; i++) {
		for (ll j = i; j < 1000001LL; j+=i) {
			a[j] += i;
		}
		a[i] += a[i - 1];
	}
	while (b--) {
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", a[n]);
	}
}