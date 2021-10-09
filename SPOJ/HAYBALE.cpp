// https://www.spoj.com/problems/HAYBALE/en/

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
typedef long long ll;
 
int main() {
    IO();
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<ll> v(n + 1);
    for(int i = 1; i <= k; i++){
        int a, b; cin >> a >> b;
        v[a]++;
        if(b + 1 != n)
        v[b + 1]--;
    }
    for(int i = 1; i < v.size(); i++) v[i] += v[i - 1];
    sort(v.begin(), v.end());
    cout << v[n / 2];
}
