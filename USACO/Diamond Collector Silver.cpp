// http://www.usaco.org/index.php?page=viewproblem2&cpid=643

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
int main() {
    IO();
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<ll> v(n), greatRight(n), greatLeft(n);
    for(int i = 0 ; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll l = n - 1;
    greatRight[l] = 1;
    for(int r = n - 2; r >= 0; r--){
        while(v[l] - v[r] > k) l--;
        greatRight[r] = max(l - r + 1, greatRight[r + 1]);
    }
    ll r = 0;
    greatLeft[r] = 1;
    for(int l = 1; l < n; l++){
        while(v[l] - v[r] > k) r++;
        greatLeft[l] = max(l - r + 1, greatLeft[l - 1]);
    }
    ll ans = 0;
    for(int i = 1; i < n; i++){
        ans = max(ans, greatLeft[i - 1] + greatRight[i]);
    }
    cout << ans;
}
