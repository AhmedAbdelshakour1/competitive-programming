// http://www.usaco.org/index.php?page=viewproblem2&cpid=918

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
typedef long long ll;
int mn(vector<int> &v){
    int n = v.size();
    int ans = 0;
    if((v[n - 1] - v[1] == n - 2 && v[1] - v[0] > 2) || (v[n - 2] - v[0] == n - 2 && v[n - 1] - v[n - 2] > 2)) ans = 2;
    else{
        int p2 = 0, range = 0, maxRange = 0;
        for(int p1 = 0; p1 < n; p1++){
            while(p2 < n && (v[p2] - v[p1] < n)) p2++;
            range = p2 - p1;
            maxRange = max(maxRange, range);
        }
        ans = n - maxRange;
    }
    return ans;
}
int main() {
    IO();
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << mn(v) << "\n" << max(v[n - 1] - v[1], v[n - 2] - v[0]) - (n - 2);
}
