// https://atcoder.jp/contests/abc154/tasks/abc154_b?lang=en

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nline '\n';
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

//.....................................................................................//
const int MOD = 1e9 + 7;

int main() {
     string s; cin >> s;
     string st = s;
    reverse(all(st));
    if(st == s){
        cout << "Yes";
        exit(0);
    }
    reverse(all(st));
    int n = len(s), cnt = 0;
    bool f = false;
    for(int i = n - 1; i > 0; i--){
        if(st[i] == '0' && st[i - 1] != '0'){
            cnt++;
            break;
        }else  if(st[i] == '0' && st[i - 1] == '0'){
            cnt++;
        }
        if(i == 1) f = true;
    }
    if(st[0] == '0' && f) cnt++;
    reverse(all(st));
    for(int i = 0; i < cnt; i++) st.push_back('0');
    string temp = st;
    reverse(all(temp));
    if(st == temp){
        cout << "Yes";
    }else cout << "No";
}
