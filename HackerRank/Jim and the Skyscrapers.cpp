// https://www.hackerrank.com/challenges/jim-and-the-skyscrapers/problem

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
int dy4[4] = {-0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const ll OO = 1e8;


ll pw(ll b, ll p) {   // O(log(p) base 2)
    if (p == 0 && b == 0) return 0;
    if (p == 0) return 1;
    ll sq = pw(b, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * b;
    return sq;
}

void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

//.....................................................................................//

int main(){
    int n; scanf("%d", &n);
    stack<pair<int, int>> st;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int h;
        scanf("%d", &h);
        while(!st.empty() && h > st.top().first) st.pop();
        if(!st.empty() && h == st.top().first) {
            // ans += st.top().second; st.top().second++;
            ans += st.top().second++;
        }else st.push({h, 1});
    }
    printf("%lld", ans * 2);
}
