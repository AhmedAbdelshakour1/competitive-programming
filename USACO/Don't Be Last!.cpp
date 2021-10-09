// http://www.usaco.org/index.php?page=viewproblem2&cpid=687

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
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int n, milk;
    string name;
    map<string, int> mp;
    scanf("%d", &n);
    rep(i, 0, n) {
        cin >> name >> milk;
        mp[name] += milk;
    }
    vector<pair<int, string>> v;
    for(auto &a : mp) v.pb(make_pair(a.sec, a.fir));
    sort(all(v));
    int mn = v[0].fir;
    string s = "";
 
    if(mp.size() == 7) {
    int flag = 0;
    rep(i, 0, v.size()){
        if(v[i].fir > mn) {
            s = v[i].sec;
            flag = i;
            break;
        }
    }
    if(flag != v.size() - 1) {
        if (v[flag].fir != v[flag + 1].fir) cout << s << endl;
        else cout << "Tie" << endl;
    }else cout << s << endl;
 
    }else {
        int counter = 0;
        rep(i, 0, n){
            if(v[i].fir == mn) counter++;
        }
        if(counter == 1) cout << v[0].sec << endl;
        else cout << "Tie" << endl;
    }
}
