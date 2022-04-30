//1456 : 거의 소수
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dp[10000001];
vector<int> Prime;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll A, B;
    cin >> A >> B;
    for (int i = 2; i < 10000001; i++) {
        if (dp[i]) continue;
        Prime.push_back(i);
        for (int j = 2 * i; j < 10000001; j += i) dp[j] = true;
    }
    ll ans = 0LL;
    for (auto it : Prime) {
        ll curr = 1LL * it;
        ll temp = curr;
        while (temp <= B / curr) {
            temp *= curr;
            if (temp >= A) ans++;
        }
    }
    cout << ans << '\n';
}