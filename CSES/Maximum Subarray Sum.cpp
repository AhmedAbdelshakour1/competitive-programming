// https://cses.fi/problemset/task/1643/

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
typedef long long ll;
 
 
int main() {
    IO();
    int n; cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll res = INT_MIN, sum = 0;
    for(ll curr : v){
        sum += curr;
        res = max(res, sum);
        sum = max(sum, 1ll*0);
    }
    cout << res;
}
 
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
     No idea is a BAD idea!
     NEVER to assume something not mentioned!
     Thinking Concretely, Symbolically, Pictorically..
     Think in the smallest boundaries (e.g. n = 0, 1, 2 - R*C = {1*1, 1*2, 2*1, 2, 2} - str = "", str = "a", ...)
     Think in the largest boundaries (e.g. n = MAX, array is fully, string has max characters, ...)
     Think in especial cases (array filled with zeros, 1 1 1 1, .....)
     Make sure that you know exactly what is output and its "format"
 */
