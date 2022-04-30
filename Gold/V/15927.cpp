//15927 : 회문은 회문아니야!!
#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	string s;
	cin >> s;
	int a = 0;
	for (int i = 0; i < s.size() / 2; i++)
		if (s[i] != s[s.size() - i - 1]) {
			cout << s.length();
			return 0;
		}
		else if (s[i] != s[i + 1]) a = 1;
	if (a) cout << s.length() - 1;
	else cout << -1;
}