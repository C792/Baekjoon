//7086 : GCD!

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    while (1) {
        cin >> n >> m;
        if (cin.eof()) break;
        ll ans = 1;
        for (int i = 2; i * i <= m; i++) {
            int cm = 0;
            while (!(m % i)) {
                m /= i;
                cm++;
            }
            int cn = 0;
            if (cm > 0) {
                for (int j = i; j <= n; j *= i)
                    cn += n / j;
            }
            ans *= pow(i, min(cn, cm));
            if (m < i) break;
        }
        if (m > 1 && m < n) ans *= m;
        cout << ans << "\n";
    }
}