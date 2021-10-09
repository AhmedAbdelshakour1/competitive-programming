// http://www.usaco.org/index.php?page=viewproblem2&cpid=619

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
typedef long long ll;
 
int main() {
    IO();
    freopen ("balancing.in" , "r", stdin);
    freopen ("balancing.out", "w", stdout);
    int n; cin >> n;
    pair<int, int> p[n];
    for(int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        int upperL = 0, upperR = 0, lowerL = 0, lowerR = 0;
        for(int j = 0; j < n; j++){
            if(p[j].second > p[i].second + 1) upperR++;
            else lowerR++;
        }
        for(int j = 0; j < n; j++){
            if( p[j].second > p[i].second + 1){
                upperR--;
                upperL++;
            }else if(p[j].second < p[i].second + 1){
                lowerR--;
                lowerL++;
            }
            ans = min(ans, max({upperR, upperL, lowerR, lowerL}));
        }
 
    }
    cout << ans;
}
