//10986 : 나머지 합
#include <iostream>
typedef long long ll;
using namespace std;

ll s, re[1001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll in;
        cin >> in;
        s += in;
        re[s % m]++;
    }
    for (int i = 0; i < 1001; i++) ans += re[i] * (re[i] - 1) / 2;
    ans += re[0];
    cout << ans;
}