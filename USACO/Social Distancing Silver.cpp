// http://www.usaco.org/index.php?page=viewproblem2&cpid=1038

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
ll n, m;
vector<pair<ll, ll>> v;
bool valid(ll d){
    ll cnt = 1, curDis = v[0].first;
    for(auto &i : v){
        if(curDis + d <= i.first){
            curDis = i.first;
            cnt++;
        }
       while(curDis + d <= i.second && curDis + d >= i.first){
           curDis += d;
           cnt++;
       }
        if(cnt >= n) break;
    }
    return cnt >= n;
}
ll bs(){
    ll st = 1, end = 1e18;
    while(st + 1 < end){
        ll mid = st + (end - st) / 2;
        if(valid(mid)) st = mid;
        else end = mid;
    }
    return st;
}
int main() {
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    IO();
    cin >> n >> m;
    v.resize(m);
    for(auto &i : v) cin >> i.first >> i.second;
    sort(v.begin(), v.end());
    cout << bs();
}
