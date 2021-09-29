// https://cses.fi/problemset/task/1620/

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
ll n, t;
vector<ll> v;
bool valid(ll time){
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        sum += time / v[i];
        if(sum >= t) break;
    }
    return sum >= t;
}
ll bs(){
    ll st = 1, end = 1e18;
    for(int i = 0; i < 100; i++){ //0000011111
        ll mid = st + (end - st) / 2;
        if(valid(mid)) end = mid;
        else st = mid;
    }
    return end;
}
int main() {
    IO();
    cin >> n >> t;
    v.resize(n);
    for(ll &i : v) cin >> i;
    cout << bs() << endl;
}
