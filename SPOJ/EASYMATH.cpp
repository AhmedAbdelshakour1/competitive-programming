// https://www.spoj.com/problems/EASYMATH/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
const double PI = 2 * asin(1);
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
ll lcm(ll a, ll b){
    return (a * b) / __gcd(a, b);
}
ll v[5];
 
ll IX(ll mm, int idx = 0, ll div = 1, int sign = 1){
    if(idx == 5){
        return sign * mm / div;
    }
    return IX(mm,idx + 1, div, sign) + IX(mm,idx + 1, lcm(div , v[idx]), sign * - 1);
}
int main() {
    //IO();
    int t;
    scanf("%d", &t);
    while(t--) {
        ll n, m, a, d;
        scanf("%lld %lld %lld %lld", &n, &m, &a, &d);
        v[0] = a;
        v[1] = a + d;
        v[2] = a + 2 * d;
        v[3] = a + 3 * d;
        v[4] = a + 4 * d;
        printf("%lld\n", IX(m) - IX(n - 1));
    }
}
