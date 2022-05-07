//1644 : 소수의 연속합
#include<iostream>
#define M 4000000

using namespace std;

int p_sum[300000]{0};
bool p[M] = { 1,1,0 };
void primechk(int m) {
    for (int i = 2; i <= m; i++)
        if (!p[i])
            for (int j = 2 * i; j <= m; j += i)
                p[j] = 1;
    int k = 1;
    for (int i = 0; i <= m; i++) if (!p[i]) p_sum[k++] = i + p_sum[k - 1];
}
int cnt, r, l, t, sum;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;

    primechk(M);

    while (r<300000) {
        if (p_sum[r] - p_sum[l] > t) {
            l++;
        }
        else if (p_sum[r] - p_sum[l] < t) {
            r++;
        }
        else {
            cnt++;
            r++;
        }
    }
    cout << cnt;
}