// http://www.usaco.org/index.php?page=viewproblem2&cpid=915

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
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<int> v(3);
    forl(i, 0, 3) cin >> v[i];
    sort(all(v));
    int a = v[0], b = v[1], c = v[2];
    if((b - 1) == a && (b + 1) == c){
        cout << 0 << "\n" << 0;
        return 0;
    }
    if(a + 2 == b || b + 2 == c)
        cout << 1 << "\n";
    else cout << 2 << "\n";
    cout << max(b - a, c - b) - 1;
}
