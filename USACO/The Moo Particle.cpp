// http://www.usaco.org/index.php?page=viewproblem2&cpid=1040

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
 
int main(){
    IO();
    freopen("moop.in","r",stdin);
    freopen("moop.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    vector<int> minl(n), maxr(n);
    minl[0] = v[0].second;
    maxr[n - 1] = v[n - 1].second;
    for(int i = 1; i < n; i++)
        minl[i] = min(minl[i - 1], v[i].second);
    for(int i = n - 2; i >= 0; i--)
        maxr[i] = max(maxr[i + 1], v[i].second);
    //at least we have one connected component.
    int ans = 1;
    for(int i = 0; i < n - 1; i++){
        if(minl[i] > maxr[i + 1]) ans ++;
    }
    cout << ans << endl;
}
