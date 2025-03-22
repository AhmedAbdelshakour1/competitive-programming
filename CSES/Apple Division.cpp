// https://cses.fi/problemset/task/1623/

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
 
vector<ll> v;
ll subsets(int mask){
    int idx = 0;
    ll sum = 0;
    while(mask){
        if(mask & 1) sum += v[idx];
        idx++;
        mask >>= 1;
    }
    return sum;
}
int main() {
    IO();
    int n, var;
    cin >> n;
    ll ans = LONG_LONG_MAX;
    forl(i, 0, n){
        cin >> var;
        v.pb(var);
    }
    forl(i, 0, (1 << n)){
        ll groupA = subsets(i);
        ll groupB = subsets(~i & (1 << v.size()) - 1);
        ans = min(ans, abs(groupA - groupB));
    }
    cout << ans;
}


// Another solution
const int N = 20;
int v[N], n;
ll ans = OO, sum = 0;
void solve(int indx, ll sum1){
    if(indx == n){
        ll sum2 = sum - sum1;
        ans = min(ans, abs(sum1 - sum2));
        return;
    }
    solve(indx + 1, sum1);
    solve(indx + 1, sum1 + v[indx]);
}
