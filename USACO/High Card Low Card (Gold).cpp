// http://www.usaco.org/index.php?page=viewproblem2&cpid=573

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
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n, ans = 0; cin >> n;
    vector<int> ellF;
    vector<int> ellS;
    vector<int> bes;
    vector<bool> used(2 * n + 1);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(i < n / 2)
            ellF.push_back(x);
        else ellS.push_back(x);
        used[x] = 1;
    }
    for(int i = 1; i <= 2 * n; i++){
        if(!used[i])
            bes.push_back(i);
    }
    sort(ellF.begin(), ellF.end());
    sort(ellS.begin(), ellS.end());
    int indx = bes.size() - 1;
    for(int i = ellF.size() - 1; i >= 0; i--){
        if(bes[indx] > ellF[i]) {
            ans++;
            indx--;
        }
    }
    indx = 0;
    for(int i = 0; i < ellS.size(); i++){
        if(bes[indx] < ellS[i]){
            ans++;
            indx++;
        }
    }
    cout << ans << '\n';
}
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
