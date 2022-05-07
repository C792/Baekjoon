//10989 : 수 정렬하기 3
#include<iostream>
#include<algorithm>
using namespace std;

int chk[10000];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		chk[in]++;
	}
	for (int i = 0; i < 10000; i++) {
		while (chk[i]) {
			cout << i << '\n';
			chk[i]--;
		}
	}
}