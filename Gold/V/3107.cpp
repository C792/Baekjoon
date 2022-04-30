//3107 : IPv6
#include<iostream>
#include<string>

using namespace std;

string rec(string a) {
    if (a.size() >= 4) return a;
    return rec("0" + a);
}

int main() {
    string in, spl[8]{};
    cin >> in;
    int l = in.size(), p = 0;
    for (int i = 0; i < l; i++) {
        if (in[i] == ':') {
            if (in[i + 1] == ':') {
                spl[p] = rec(spl[p]);
                i++;
                int cnt = 0;
                for (int j = i; j < l; j++) if (in[j] == ':') cnt++;
                p = 8 - cnt;
                continue;
            }
            spl[p] = rec(spl[p]);
            p++;
            continue;
        }
        spl[p] += in[i];
    }
    spl[p] = rec(spl[p]);
    if (spl[0] == "\0") cout << "0000";
    else cout << spl[0];
    for (int i = 1; i < 8; i++) {
        if (spl[i] == "\0") cout << ":0000";
        else cout << ':' << spl[i];
    }
}