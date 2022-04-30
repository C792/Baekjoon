//2892 : 심심한 준규
#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> hex >> k;
		if (k >= 64) cout << '-';
		else cout << '.';
	}
}