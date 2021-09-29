// https://cses.fi/problemset/task/1661/

/// You just can't beat the person who never gives up.
#include <bits/stdc++.h>
 
using namespace std;
#define all(x) (x).begin(), (x).end()
#define len(x) (int)x.size()
typedef long long ll;
typedef unsigned int uit;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define newline "\n"
#define fir first
#define sec second
#define pi 3.141592653589793
#define e 2.718281828459045
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main() {
    IO();
    ll n, x, ans = 0;  cin >> n >> x;
    vector<ll> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) v[i] += v[i - 1];
 
    map<ll, int> m;
    for(int i = 1; i <= n; i++){
        if(v[i] == x) ans++;
        if(m.find(v[i] - x) != m.end()) ans += m[v[i] - x];
        m[v[i]]++;
    }
    cout << ans;
}
