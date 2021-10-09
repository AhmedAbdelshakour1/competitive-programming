// http://www.usaco.org/index.php?page=viewproblem2&cpid=714

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
typedef long long ll;
bool compare(pair<ll, ll> &a, pair<ll, ll> &b) {
    return a.second < b.second;
}
 
int main() {
    IO();
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int c, n; cin >> c >> n;
    multiset<ll> ch;
    pair<ll, ll> cows[n];
    for(int i =  0; i < c; i++){
        int x; cin >> x;
        ch.insert(x);
    }
    for(int i = 0; i < n; i++) cin >> cows[i].first >> cows[i].second;
    sort(cows, cows + n, compare);
    int ans = 0;
    for(auto &p : cows){
        auto it = ch.lower_bound(p.first);
        if(it != ch.end() && *it <= p.second){
            ch.erase(it);
            ans++;
        }
    }
    cout << ans << '\n';
}
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
