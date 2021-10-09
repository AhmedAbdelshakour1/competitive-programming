// http://www.usaco.org/index.php?page=viewproblem2&cpid=787

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
int main() {
    IO();
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> v(n), r(c);
    vector<pair<int, int>> s(m);
    for(int &i : v) cin >> i;
    for(auto &i : s) cin >> i.second >> i.first;
    for(int &i : r) cin >> i;
    sort(v.rbegin(), v.rend());
    sort(r.rbegin(), r.rend());
    sort(s.rbegin(), s.rend());
    int i = 0, is = 0, ir = 0;
    ll ans = 0;
    while(i < n){
        int currL = v[i];
        ll money = 0, curIs = is, lastBuy = 0;
        while(curIs < m){
            int l = min(s[curIs].second, currL);
            money += l * s[curIs].first;
            currL -= l;
            if(currL == 0){
                lastBuy = l;
                break;
            }else curIs++;
        }
        if(ir >= c || money > r[ir]){
            ans += money;
            is = curIs;
            i++;
            if(is < m) s[is].second -= lastBuy;
        }else {
            ans += r[ir];
            ir++;
            //rent from last.
            n--;
        }
    }
    cout << ans;
}
