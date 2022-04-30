//9997 : 폰트
#include<iostream>
#include<string>

using namespace std;

int n, ans, dp[25]{};

void check(int m, int bit) {
	if (bit == (1 << 26) - 1) ans++;
	for (int i = m + 1; i < n; i++) {
		int l = bit | dp[i];
		check(i, l);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			int a = str[j] - 'a';
			dp[i] = dp[i] | (1 << a);
		}
	}
	check(-1,0);
	cout << ans;
}