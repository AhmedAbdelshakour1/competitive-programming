// http://www.usaco.org/index.php?page=viewproblem2&cpid=667

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
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
 
//void IO(){
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//}
 
 
 
int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int n, ans = 0;
    string st, ch;
    scanf("%d", &n);
    map<pair<string, string>, int > mp;
 
    rep(i, 0, n){
    cin >> st >> ch;
    if(st.substr(0, 2) != ch) mp[make_pair(st.substr(0, 2), ch)]++;
    }
    for(auto &c : mp){
        auto keyMp = c.fir;
        int rp = c.sec;
        if(mp.count(make_pair(keyMp.sec, keyMp.fir)))
            ans += rp * mp[make_pair(keyMp.sec, keyMp.fir)];
    }
    printf("%d", ans / 2);
}
