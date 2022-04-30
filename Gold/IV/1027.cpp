//1027 : 고층 건물
#include <iostream>
using namespace std;
typedef long long ll;
ll in[51],dh;
int n, out;
int main() {
    int max = -1;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dh = in[j] - in[i];
            bool see = true;
            if (i == j)continue;
            if (i < j) {
                int d = j - i;
                for (int k = 1; k < d; k++) if (in[i] * d + dh * k <= in[i + k] * d) see = false;
            }
            else {
                int d = i - j;
                for (int k = 1; k < d; k++) if (in[i] * d + dh * k <= in[i - k] * d) see = false;
            }
            if (see) out++;
        }
        if (out > max) max = out;
        out = 0;
    }
    cout << max;
}