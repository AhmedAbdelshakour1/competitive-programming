// http://www.usaco.org/index.php?page=viewproblem2&cpid=785

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
#define INF 0x3f3f3f3f
 
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main() {
    IO();
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int n, ans = 0, mn = INT_MAX, mx = INT_MIN, indxMn = -1, indxMx = -1;
    cin >> n;
    vector<int> v(n);
    vector<int> sorted(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sorted[i] = v[i];
    }
    sort(all(sorted));
    for(int i = 0; i < n; i++){
        if(sorted[i] != v[i])
            ans++;
    }
    cout << ans - 1;
}
