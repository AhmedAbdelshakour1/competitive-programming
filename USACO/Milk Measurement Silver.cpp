// http://www.usaco.org/index.php?page=viewproblem2&cpid=763

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
typedef long long ll;
struct measurements{
    int day;
    int id;
    int val;
};
int main(){
    IO();
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    ll n, g; cin >> n >> g;
    vector<measurements> v(n);
    for(auto &m : v)
        cin >> m.day >> m.id >> m.val;
 
    sort(v.begin(), v.end(), [](const measurements& a, const measurements& b){ return a.day < b.day;});
 
    map<int, int, greater<int>> cntWMax;
    cntWMax[0] = n;
    map<int, int> cows;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int maxOldValue = cntWMax.begin()->first;
        cntWMax[cows[v[i].id]]--;
        bool isOldTop = cows[v[i].id] == maxOldValue;
        int oldVal = cows[v[i].id];
        int countOldVal = cntWMax[oldVal];
        if(cntWMax[cows[v[i].id]] == 0)
            cntWMax.erase(cows[v[i].id]);
 
        cows[v[i].id] += v[i].val;
        cntWMax[cows[v[i].id]]++;
        if(isOldTop){
            int curMaxVal = cntWMax.begin()->first;
            int count = cntWMax.begin()->second;
            if((curMaxVal > cows[v[i].id]) || (oldVal > curMaxVal && count > 1) || (curMaxVal > oldVal && countOldVal >= 1))
                ans++;
        }else if(cows[v[i].id] >= maxOldValue) ans++;
    }
    cout << ans;
}
