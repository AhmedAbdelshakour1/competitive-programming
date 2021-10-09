// http://www.usaco.org/index.php?page=viewproblem2&cpid=893

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
int common(vector<string> &v1, vector<string> &v2){
    map<string, int> m;
    int counter = 0;
    for(auto a : v1) m[a]++;
    for(auto a : v2) m[a]++;
    for(auto  a : m){
        if(a.sec > 1) counter++;
    }
    return counter;
}
int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    IO();
    int n; cin >> n;
    vector<vector<string>> v;
 
    forl(i, 0, n){
        string s;
        int k;
        cin >> s >> k;
        vector<string> t(k);
        forl(j, 0, k){
            cin >> t[j];
        }
        v.pb(t);
    }
    int ans = 0;
    forl(i, 0, n) {
        forl(j, i + 1, n) {
            ans = max(ans, common(v[i], v[j]));
        }
    }
    cout << ans + 1;
}
