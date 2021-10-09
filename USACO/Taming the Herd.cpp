// http://www.usaco.org/index.php?page=viewproblem2&cpid=809

 copy
/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define forl(i, a, n) for(int i = a; i < n; i++)
#define forn(i, a, n) for(int i = a; i <= ; i++)
#define all(x) (x).begin(), (x).end()
#define len(x) (int)x.size()
typedef long long ll;
typedef unsigned int uit;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define fir first
#define sec second
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
 
void IO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
 
int main() {
    IO();
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    forl(i, 0, n) cin >> v[i];
    if(v[0] > 0){
        cout << -1; return 0;
    }
    v[0] = 0;
    int mn = 0, mx = 0;
    for(int i = n - 1; i > 1; i--){
        if(v[i] > 0) {
            if (v[i - 1] > 0 && v[i] - v[i - 1] != 1) {
                cout << -1;
                return 0;
            }
            v[i - 1] = v[i] - 1;
        }
    }
    for(int i = n - 1; i > 0; i--){
        if(v[i] > 0 && v[i - 1] > 0 && v[i] - v[i - 1] != 1){
            cout << -1; return 0;
        }
        if(v[i] == -1) mx++;
    }
 
    forl(i, 0, n){
        if(v[i] == 0) mn++;
    }
    cout << mn << ' ' << mn + mx;
}
