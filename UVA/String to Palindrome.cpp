// https://vjudge.net/problem/UVA-10739

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nline '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const ll OO = 1e18;
const double eps = 1e-9;

int dcomp(double a, double b) {
    return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1;
}

bool powerOfTwo(int n) {
    return n && (!(n & (n - 1)));
}

void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll pw(ll a, ll p) {
    ll result = 1;
    while (p > 0) {
        if (p & 1) result *= a;
        a *= a;
        p >>= 1;
    }
    return result;
}

//.........................................(^_^)............................................//
const int N = 1e3 + 10;
int memo[N][N];
string s;
int best(int st, int end){
    if(st >= end) return 0;
    int &ret = memo[st][end];
    if(~ret) return ret;
    ret = best(st + 1, end - 1) + (s[st] != s[end]);
    ret = min(ret, best(st + 1, end) + 1);
    ret = min(ret, best(st, end - 1) + 1);
    return ret;
}
//another way to avoid stackOverFlow
struct state{
    int fir, sec;
    bool isProcessed;
    state(int fir, int sec) : fir(fir), sec(sec), isProcessed(false){}
};

int best(int st, int end) {
    stack<state> stm;
    stm.push(state(st, end));
    while (!stm.empty()) {
        auto curr = stm.top();
        st = curr.fir, end = curr.sec;
        stm.pop();
        if(memo[st][end] == -1){
            if(st >= end)
                memo[st][end] = 0;
            else if(!curr.isProcessed){
                curr.isProcessed = 1;
                stm.push(curr);
                stm.push(state(st + 1, end - 1));
                stm.push(state(st + 1, end));
                stm.push(state(st, end - 1));
            }else memo[st][end] = min(memo[st + 1][end - 1] + (s[st] != s[end]), min(memo[st + 1][end] + 1, memo[st][end - 1] + 1));
        }
    }
    return memo[0][len(s) - 1];
}
int main(){
    IO();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        memset(memo, -1, sizeof memo);
        cin >> s;
        cout << "Case " << i << ": " << best(0, len(s) - 1) << nline;
    }

}

