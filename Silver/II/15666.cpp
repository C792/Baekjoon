//15666 : N과 M (12)

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[10], in[10];

void f(int x, int l) {
    if (l == m) {
        for (int i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    int t = 0;

    for (int i = x; i < n; i++) {
        if (in[i] != t) {
            arr[l] = in[i];
            t = arr[l];
            f(i, l + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> in[i];

    sort(in, in + n);
    f(0, 0);
}