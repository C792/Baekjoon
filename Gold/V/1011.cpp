//1011 : Fly me to the Alpha Centauri
#include <iostream>
#include <math.h>

using namespace std;

int TC = 0;
int x, y, length, d = 0;
int move_count = 0;

int main(void) {
    scanf("%d", &TC);
    for(int i = 0; i < TC; i++) {
        scanf("%d %d", &x, &y);
        length = y - x;
        d = sqrt(length);
        pow(d, 2) == length ? move_count = 2 * d - 1 : move_count = 2 * d;
        if (length > d * (d + 1)) move_count += 1;
        printf("%d\n", move_count);
    }
}