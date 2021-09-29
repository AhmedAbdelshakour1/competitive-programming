// https://cses.fi/problemset/task/1662/

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
    ll n, ans = 0; cin >> n;
    vector<ll> v(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) v[i] = (v[i] + v[i - 1] + n * n) % n;
    map<int, vector<int>> mp;
    for(int i = 0; i <= n; i++) mp[v[i]].pb(i);
    for(auto &x : mp){
        if(x.second.size() > 1)
        ans += (x.sec.size()) * (x.sec.size() - 1) / 2;
    }
    cout << ans;
}
