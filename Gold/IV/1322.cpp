//1322 : X와 K
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ull x, k, ans = 0;
    cin >> x >> k;
    int i = 63;
    queue<int> ind;
    while (x) {
        ull t = x % 2ULL;
        if (!t) ind.push(i);
        i--;
        x /= 2ULL;
    }
    while (i) ind.push(i--);
    while (k) {
        ans |= ((k % 2ULL) << (63 - ind.front()));
        ind.pop();
        k /= 2ULL;
    }
    cout << ans;
}