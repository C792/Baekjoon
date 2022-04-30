//11687 : 팩토리얼 0의 개수
#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = n * 5; 1; i -= 5) {
		int a = i / 5 + i / 25 + i / 125 + i / 625 + i / 3125 + i / 15625 + i / 78125 + i / 390625 + i / 1953125 + i / 9765625 + i / 48828125 + i / 244140625;
		if (a == n) {
			cout << i;
			break;
		}
		else if (a < n - 1) {
			cout << -1;
			break;
		}
	}
}