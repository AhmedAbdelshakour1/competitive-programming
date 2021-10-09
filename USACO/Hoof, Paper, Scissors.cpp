// http://www.usaco.org/index.php?page=viewproblem2&cpid=691

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
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int MaxWin(int p[], int s[]){
    int subAns = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            subAns = max(subAns, p[i] + s[j]);
    }
    return subAns;
}
 
int main() {
    IO();
    freopen ("hps.in", "r", stdin);
    freopen ("hps.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    int letters[n], pre[n][3] = {0, 0}, suf[n][3] = {0, 0};
    for(int i = 0; i < n; i++){
        char let; cin >> let;
        if(let == 'P')
            letters[i] = 0;
        else if(let == 'H')
            letters[i] = 1;
        else letters[i] = 2;
    }
    for(int i = 0; i < n; i++){
        pre[i][letters[i]]++;
        suf[i][letters[n - i - 1]]++;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            pre[i][j] += pre[i - 1][j];
            suf[i][j] += suf[i - 1][j];
        }
    }
    for(int i = 0, j = n - 2; i < n - 1, j >= 0; i++, j--)
        ans = max(ans, MaxWin(pre[i], suf[j]));
 
    cout << ans << newline;
}
