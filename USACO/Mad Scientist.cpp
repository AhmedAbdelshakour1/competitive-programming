// http://www.usaco.org/index.php?page=viewproblem2&cpid=1012

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
 
typedef vector<int> vi;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main() {
    IO();
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    bool mis = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            if (!mis) {
                mis = true;
                ans++;
            }
        } else mis = false;
    }
    cout << ans << newline;
}
