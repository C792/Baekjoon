//11729 : 하노이 탑 이동 순서
#include <stdio.h>
int n;
int pwr(int x, int y) {
    if (y == 0) return 1;
    else return pwr(x, y - 1) * x;
}
void md(int i, char t, char d) {
    printf("%c %c\n", t, d);
}
void hanoi(int num, int index, char init, char des) {
    if (num == 1) {
        md(index, init, des);
        return;
    }
    hanoi(num - 1, index - 1, init, '1' + '2' + '3' - init - des);
    md(index, init, des);
    hanoi(num - 1, index - 1, '1' + '2' + '3' - init - des, des);
}
int main() {
    scanf("%d", &n);
    printf("%d\n", pwr(2, n) - 1);
    hanoi(n, n, '1', '3');
}