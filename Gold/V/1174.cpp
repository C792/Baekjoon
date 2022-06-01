//1083 : 줄어드는 수
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   int N;
   cin >> N;
   N--;
   vector<ll> v = {0,1,2,3,4,5,6,7,8,9};

   int n = 0;
   if (N >= v.size()) {
       while (v.size() != N + 1) {
           int temp = 0;
           if (n >= v.size()) break;
           while (temp < v[n] % 10) {
               v.push_back(v[n] * 10 + temp);
               temp++;
               if (v.size() == N + 1) break;
           }
           n++;
       }
   }
   if (N >= v.size()) cout << -1;
   else cout << v[N];
}