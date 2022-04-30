//9020 : 골드바흐의 추측
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int arr[10005];
typedef long long ll;
bool prime(ll n)
{
    for (ll i = 2; i <= n; i++) arr[i] = i;
    for (ll i = 2; i <= n; i++) {
        if (arr[i] == 0) continue;
        for (int j = i + i; j <= n; j += i) arr[j] = 0;
    }

    if (arr[n] == 0) return false;
    else return true;
}
void GB(ll num)
{
    ll num2 = num / 2;
    if (prime(num2)) {
        printf("%lld %lld\n", num2, num2);
        return;
    }
    else {
        while (1) {
            num2--;
            if (prime(num2)) {
                if (prime(num - num2)) {
                    printf("%lld %lld\n", num2, num - num2);
                    return;
                }
            }
        }
    }
}
int main() {
    int test; scanf("%d", &test);
    ll num;
    for (int i = 0; i < test; i++) {
        scanf("%lld", &num);
        GB(num);
    }
    return 0;
}