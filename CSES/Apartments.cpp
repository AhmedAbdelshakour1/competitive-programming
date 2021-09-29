// https://cses.fi/problemset/task/1084/

#include <bits/stdc++.h>
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main() {
    IO();
    long long n, m, k, indxD = 0, indxV = 0, ans =0;
    cin >> n >> m >> k;
    vector<long long> d(n);
    vector<long long> v(m);
    for(int i = 0; i < n; i++) cin >> d[i];
    for(int j = 0; j < m; j++) cin >> v[j];
    sort(v.begin(), v.end());
    sort(d.begin(), d.end());
    while(indxD < n && indxV < m){
        if(abs(v[indxV] - d[indxD]) <= k){
            ans++;
            indxD++;
            indxV++;
        }else {
            if(v[indxV] - d[indxD] > k) indxD++;
            else indxV++;
        }
    }
    cout << ans;
}
 
 
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
