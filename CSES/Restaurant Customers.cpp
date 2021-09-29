// https://cses.fi/problemset/task/1619/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
 
const int MAX = 1e6 + 1;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
int main() {
    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b + 1, -1});
    }
    int sum = 0, res = 0;
    sort(v.begin(), v.end());
    for(auto &i : v){
        sum += i.second;
        res = max(res, sum);
    }
    cout << res;
}
