// http://www.usaco.org/index.php?page=viewproblem2&cpid=896

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
struct peek{
    int x, y;
};
bool comp(peek &a, peek &b){
    if(a.x == b.x) return b.y < a.y;
    return a.x < b.x;
}
int main(){
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    IO();
    int n; cin >> n;
    vector<peek> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a - b, a + b});
    }
    sort(v.begin(), v.end(), comp);
    int ans = 1, mostPeek = v[0].y;
    for(int i = 1; i < n; i++){
        if(v[i].y > mostPeek){
            ans++;
            mostPeek = v[i].y;
        }
    }
    cout << ans << endl;
}
