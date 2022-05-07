//1016 : 제곱 ㄴㄴ 수
#include<iostream>

using namespace std;

typedef long long ll;

ll num[1000002];

bool prime[1000002] = { 1,1,0 };

int main() {
    ll min, max;
    int cnt = 0, l = 0;
    cin >> min >> max;
    for (ll i = 2; i * i <= max + 1; i++)
        if (!prime[i])
            for (ll j = 2 * i; j * j <= max + 1; j += i)
                prime[j] = 1;

    for (ll i = 2; i * i <= max + 1; i++) {
        if (!prime[i]) {
            for (ll j = i * i * (min / (i * i)); j <= max; j += i * i) {
                if (j >= min)
                    num[j - min] = 1;
            }
        }
    }

    for (int i = 0; i <= max - min; i++) {
        if (!num[i]) {
            cout << i << endl;
            cnt++;
        }
    }
    cout << cnt;
}