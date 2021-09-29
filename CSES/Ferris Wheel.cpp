// https://cses.fi/problemset/task/1090/

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main() {
    IO();
    long long n, x, ans = 0;
    cin >> n >> x;
    vector<long long> v(n);
    for (int j = 0; j < n; j++) cin >> v[j];
    sort(v.begin(), v.end());
    long long l = 0, r = n - 1;
    while(l <= r){
        if(v[l] + v[r] <= x){
            ans++;
            l++;
            r--;
        }else if(v[r] <= x){
            ans++;
            r--;
        }
    }
    cout << ans << '\n';
}
 
 
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
