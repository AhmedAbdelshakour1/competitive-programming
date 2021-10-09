// https://judge.yosupo.jp/problem/associative_array

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> m;
int main() {
    ll q, n,k, v;
    scanf("%lld", &q);
    while (q--) {
        scanf("%lld", &n);
        if (n == 0) {
            scanf("%lld %lld", &k, &v);
            m[k] = v;
        }else {
            scanf("%lld", &k);
            printf("%lld\n", m[k]);
        }
    }
}
