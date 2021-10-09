// http://www.usaco.org/index.php?page=viewproblem2&cpid=664

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
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
 
 
int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int N;
    scanf("%d", &N);
    int ar[26] = {};
    rep(i, 0, N) {
        string a, b;
        cin >> a >> b;
       int cntA[26] = {}, cntB[26] = {};
        rep(j, 0, a.size()) cntA[a[j] - 'a']++;
        rep(k, 0, b.size()) cntB[b[k] - 'a']++;
        rep(t, 0, 26) ar[t] += max(cntA[t], cntB[t]);
    }
    rep(i, 0, 26) cout << ar[i] << endl;
}
