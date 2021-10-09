// http://www.usaco.org/index.php?page=viewproblem2&cpid=715

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
int main() {
    IO();
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b;
    cin >> n >> k >> b;
    vector<int> v(n + 1);
    for(int i = 0; i < b; i++){
        int num; cin >> num;
        v[num]++;
    }
    for(int i = 1; i <= n; i++) v[i] += v[i - 1];
    int res = INT_MAX;
    for(int i = 1; i <= n; i++){
        if(i - 1 + k <= n)
        res = min(res, v[i - 1 + k] - v[i - 1]);
    }
    cout << res;
}
