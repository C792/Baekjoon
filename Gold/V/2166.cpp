//2166 : 다각형의 넓이
#include<iostream>
#include<queue>

using namespace std;

typedef long long ll;

ll vector_product(pair<ll, ll> x, pair<ll, ll>y) {
	return x.first * y.second - x.second * y.first;
}

double s;

int main() {
    queue<pair<ll, ll>> q;
    int n;
    cin >> n;
    ll ox,oy;
    cin >> ox >> oy;
    while (n---1) {
        ll a, b;
        cin >> a >> b;
        q.push({ a - ox, b - oy });
    }
    while (q.size()>1) {
        pair<ll, ll> x = q.front(), y;
        q.pop();
        y = q.front();
        s += (double)vector_product(x, y);
    }
    printf("%.1lf", abs(s));
}