//15550 : if 2
#include <iostream>
using namespace std;
int main() {
    int i = 16770000;
    while(i++) {
        int a = i;
        float b = i;
        int c = i + 1;
        if (a == b && b == c && c != a) {
            cout << i << " : " << "true" << '\n';
        }
    }
    return 0;
}