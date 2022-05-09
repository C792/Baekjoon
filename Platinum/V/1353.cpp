//1353 : 합과 곱
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int s, p;
    cin >> s >> p;
    if (s == p) {
        cout << 1;
        return 0;
    } 
    for (double i = 2; i <=s; i++) {
        if (pow(s / i, i) >= p) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}