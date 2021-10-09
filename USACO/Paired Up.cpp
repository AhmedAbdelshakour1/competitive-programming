// http://www.usaco.org/index.php?page=viewproblem2&cpid=738

 copy
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
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n; cin >> n;
    vector<pair<ll, ll>> p;
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        p.push_back({y, x});
    }
    sort(p.begin(), p.end());
    ll ans = 0, i = 0, j = n - 1, cLeft = 0, cRight = 0;
    while(i <= j){
        ans = max(ans, p[i].first + p[j].first);
        cLeft++; cRight++;
        if(cLeft == p[i].second){
            i++;
            cLeft = 0;
        }
        if(cRight == p[j].second){
            j--;
            cRight = 0;
        }
    }
    cout << ans;
}
