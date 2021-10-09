// http://www.usaco.org/index.php?page=viewproblem2&cpid=689

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
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++)
            cin >> v[i];
 
        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(v[i][j] == '1'){
                    ans++;
                    for(int k = 0; k <= i; k++){
                        for(int m = 0; m <= j; m++){
                            if(v[k][m] == '1')
                                v[k][m] = '0';
                            else v[k][m] = '1';
                        }
                    }
                }
            }
        }
    cout << ans;
}
