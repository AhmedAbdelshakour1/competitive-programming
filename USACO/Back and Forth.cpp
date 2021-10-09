// http://www.usaco.org/index.php?page=viewproblem2&cpid=857

/// You just can't beat the person who never gives up
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
#define INF 0x3f3f3f3f
 
typedef vector<int> vi;
 
void IO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
set<int> distinct;
void possible(int day, pair<int, vector<int>> P1, pair<int, vector<int>> P2){
    if(day == 4){
        distinct.insert(P1.fir);
        return;
    }
   for(int i = 0; i < P1.sec.size(); i++){
       int cur = P1.sec[i];
       vector<int> a = P1.sec;
       vector<int> b = P2.sec;
       b.pb(cur);
       a.erase(a.begin() + i);
       possible(day + 1, {P2.fir + cur, b}, {P1.fir - cur, a});
   }
}
int main(){
    freopen ("backforth.in","r",stdin);
    freopen ("backforth.out","w",stdout);
    vector<int> a(10);
    vector<int> b(10);
    for(auto &i : a)
        cin >> i;
    for(auto &i : b)
        cin >> i;
    possible(0, {1000, a}, {1000, b});
    cout << distinct.size() << newline;
}
