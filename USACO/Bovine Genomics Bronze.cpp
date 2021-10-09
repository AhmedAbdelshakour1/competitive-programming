// http://www.usaco.org/index.php?page=viewproblem2&cpid=736

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define forl(i, a, n) for(int i = a; i < n; i++)
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
 
//void IO(){
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//}
 
int n, m, ans = 0;
bool check(int j, vector<vector<char>> &spotty, vector<vector<char>> &plain){
    bool sp[202] = {}, pl[202] = {};
    forl(i, 0, n) sp[spotty[i][j]] = true;
    forl(i, 0, n) pl[plain[i][j]] = true;
    return !(sp['A'] && pl['A'] || sp['G'] && pl['G'] || sp['C'] && pl['C'] || sp['T'] && pl['T']);
}
 
int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
 
    scanf("%d %d", &n, &m);
    vector<vector<char>> spotty(n, vector<char>(m));
    vector<vector<char>> plain(n, vector<char>(m));
    forl(i, 0, n)forl(j, 0, m) cin >> spotty[i][j];
    forl(i, 0, n)forl(j, 0, m) cin >> plain[i][j];
    forl(i, 0, m) if(check(i, spotty, plain)) ans++;
    printf("%d", ans);
}
