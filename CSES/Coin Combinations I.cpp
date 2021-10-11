// https://cses.fi/problemset/task/1635/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045

const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {-0, 0, -1, 1};
ll pow(ll b, ll p) {   // O(log(p) base 2)
    if (p == 0 && b == 0) return 0;
    if (p == 0) return 1;
    ll sq = pow(b, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * b;
    return sq;
}

void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

//.....................................................................................//
const int MOD = 1e9 + 7;
int coins[104];
int memo[1000001];
int n, x;
int solve(int c){
    if(!c) return 1;
    int &ret = memo[c];
    if(~ret) return ret;
    ret = 0;
    for(int i = 0; i < n; i++){
        if(c >= coins[i]) ret = (ret % MOD + solve(c - coins[i]) % MOD) % MOD;
    }
    return ret;
}
int main() {
     cin >> n >> x;
     for(int i = 0; i < n; i++) cin >> coins[i];
     memset(memo, -1, sizeof memo);

     cout << solve(x);
}

/*
     Do not make STUPID MISTAKES!
     NEVER to assume something not mentioned!
     Thinking Concretely, Symbolically, Pictorically..
     Think in the smallest boundaries (e.g. n = 0, 1, 2 - R*C = {1*1, 1*2, 2*1, 2, 2} - str = "", str = "a", ...)
     Think in the largest boundaries (e.g. n = MAX, array is fully, string has max characters, ...)
     Think in especial cases (array filled with zeros, 1 1 1 1, .....)
     Make sure that you know exactly what is output and its "format"
*/

