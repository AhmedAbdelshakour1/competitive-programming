// http://www.usaco.org/index.php?page=viewproblem2&cpid=690

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
int n, t;
vector<int> v;
bool valid(int k){
    multiset<int> ms;
    for(int i = 0; i < k; i++) ms.insert(v[i]);
    for(int i = k; i < n; i++){
        int curr = *ms.begin();
        ms.insert(curr + v[i]);
        ms.erase(ms.find(curr));
    }
    return (*(--ms.end())) <= t;
}
int bs(){
    int st = 0, end = n;
    while(st + 1 < end){
        int mid = st + (end - st) / 2;
        if(valid(mid)) end = mid;
        else st = mid;
    }
    return end;
}
int main(){
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> n >> t;
    v.resize(n);
    for(int &i : v) cin >> i;
    cout << bs();
 
}
