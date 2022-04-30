//1759 : 암호 만들기
#include <stdio.h>
#include <algorithm>
int n, m, ans[20], chk[20];
char cov[20], vowel[] = { 'a','e','i','o','u' }, cons[] = { 'q','w','r','t','y','p','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m' };
void f(int ind, int st) {
    if (ind == m) {
        bool Pvowel = false, Pcons = false, Pcons2 = false;
        for (int i = 0; i < m; i++) for (int j = 0; j < 5; j++) if (vowel[j] == cov[ans[i] - 1]) {
            Pvowel = true;
            break;
        }
        for (int i = 0; i < m; i++) for (int j = 0; j < 21; j++) if (cov[ans[i] - 1] == cons[j]) {
            if (!Pcons) Pcons = true;
            else {
                Pcons2 = true;
                break;
            }
        }
        if (Pvowel&&Pcons2) {
            for (int i = 0; i < m; i++) printf("%c", cov[ans[i] - 1]);
            puts("");
        }
        return;
    }
    for (int i = st; i <= n; i++) {
        if (chk[i]) continue;
        chk[i]++;
        ans[ind] += i;
        f(ind + 1, i);
        ans[ind] = 0;
        chk[i]--;
    }
}
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &cov[i]);
    }
    std::sort(cov, cov + n);
    f(0, 1);
}