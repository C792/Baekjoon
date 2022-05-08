//9711 : 피보나치

#include<iostream>

typedef unsigned long long ll;

using namespace std;

ll re;

struct Det {
	ll data[2][2];
};

Det prod(Det a, Det b) {
	Det c;
	c.data[0][0] = (a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0])%re;
	c.data[0][1] = (a.data[0][0] * b.data[0][1] + a.data[0][1] * b.data[1][1])%re;
	c.data[1][0] = (a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0])%re;
	c.data[1][1] = (a.data[1][0] * b.data[0][1] + a.data[1][1] * b.data[1][1])%re;
	return c;
}

Det divide(Det a, ll n) {
	if (n > 1) {
		a = divide(a, n / 2);
		a = prod(a, a);
		if (n % 2 == 1) {
			Det b;
			b.data[0][0] = 1, b.data[0][1] = 1;
			b.data[1][0] = 1, b.data[1][1] = 0;
			a = prod(a, b);
		}
	}
	return a;
}

ll f(ll x) {
	Det a;
	a.data[0][0] = 1, a.data[0][1] = 1;
	a.data[1][0] = 1, a.data[1][1] = 0;
	a = divide(a, x);
	return a.data[0][1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    for(int i=0;i<tc;i++){
	    ll n;
    	cin >> n;
        cin >> re;
        cout << "Case #" << i+1;
        if (re==1||!n) cout << ": 0" << '\n';
	    else cout << ": "<< f(n) << '\n';
    }
}