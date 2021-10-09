// http://www.usaco.org/index.php?page=viewproblem2&cpid=786

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
struct shifts{
    int st, end;
};
bool comp(const shifts &a, const shifts &b){
    return a.st < b.st;
}
int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    IO();
    int n; cin >> n;
    vector<shifts> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].st >> v[i].end;
    sort(v.begin(), v.end(), comp);
    int converd = 0, right = 0, left = 0;
    for(int i = 0; i < n; i++){
        if(v[i].end > right){
            left = max(v[i].st, right);
            converd += v[i].end - left;
            right = v[i].end;
        }
    }
    int eraseTime = converd;
    shifts a; a.st = v[n - 1].end;
    v.push_back(a);
    right = 0;
    for(int i = 0; i < n; i++){
        int curErase = min(v[i + 1].st, v[i].end) - max(v[i].st, right);
        eraseTime = min(eraseTime, curErase);
        right = v[i].end;
    }
    cout << converd - max(eraseTime, 0);
}
