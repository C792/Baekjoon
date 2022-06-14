//1786 : 찾기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> Pi(string p) {
    int m = (int)p.size(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(string t, string p) {
    vector<int> ans, pi = Pi(p);
    int n = (int)t.size(), m = (int)p.size(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && t[i] != p[j]) j = pi[j - 1];
        if (t[i] == p[j])
            if (j == m - 1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            }
            else j++;
    }
    return ans;
}

int main() {
    string T, P;
    getline(cin, T);
    getline(cin, P);
    vector<int> m = kmp(T, P);
    cout << m.size() << '\n';
    for (int i : m)
        cout << i + 1 << ' ';
}