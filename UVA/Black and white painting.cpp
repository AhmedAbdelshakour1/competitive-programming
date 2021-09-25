// https://vjudge.net/problem/UVA-11231

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
 
int main() {
    //IO();
    int n, m, c;
    while(scanf("%d %d %d", &n, &m, &c)){
        if(n == 0 && m == 0 && c == 0) exit(0);
        ll res = ((n - 8 + 1) * (m - 8 + 1));
        if(res % 2 == 0 || res % 2 != 0 && !c) printf("%lld\n", 1ll*(res / 2));
        else printf("%lld\n", 1ll * (res / 2) + 1);
    }
}
 
/*
     Do not make STUPID MISTAKES!
     NEVER to assume something not mentioned!
     Thinking Concretely, Symbolically, Pictorically..
     Think in the smallest boundaries (e.g. n = 0, 1, 2 - R*C = {1*1, 1*2, 2*1, 2, 2} - str = "", str = "a", ...)
     Think in the largest boundaries (e.g. n = MAX, array is fully, string has max characters, ...)
     Think in especial cases (array filled with zeros, 1 1 1 1, .....)
     Make sure that you know exactly what is output and its "format"
*/
