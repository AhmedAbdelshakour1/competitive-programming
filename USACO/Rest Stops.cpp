// http://www.usaco.org/index.php?page=viewproblem2&cpid=810

/// You just can't beat the person who never gives up.
#include <bits/stdc++.h>
 
using namespace std;
#define all(x) (x).begin(), (x).end()
#define len(x) (int)x.size()
typedef long long ll;
typedef unsigned int uit;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define newline "\n"
#define fir first
#define sec second
#define pi 3.141592653589793
#define e 2.718281828459045
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    IO();
    freopen ("reststops.in","r",stdin);
    freopen ("reststops.out","w",stdout);
    map<int, ll, greater<int>> m;
    int len, n, Rf, Rb, dis, tastiness;
    cin >> len >> n >> Rf >> Rb;
    for(int i = 0; i < n; i++){
        cin >> dis >> tastiness;
        m[tastiness] = dis;
    }
    ll ans = 0, pos = 0, currDistance;
    for(auto &cur : m){
        if(cur.sec > pos){
            currDistance = cur.sec - pos;
            ans += (currDistance * Rf - currDistance * Rb) * cur.fir;
            pos = cur.sec;
        }
    }
    cout << ans << newline;
}
