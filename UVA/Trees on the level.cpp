// https://vjudge.net/problem/UVA-122

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
const ll OO = 1e18;
const double eps = 1e-9;

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
bool check(vector<pair<pair<int, string>, int>> &v, string &st , string  &sst) {
    int c = 0, f = 0;
    for (int i = 0; i < len(v); ++i) {
        if (v[i].first.second == st) f = 1;
        if (v[i].first.second == sst) c++;
    }
    return c == 1 && f;
}

bool comp(pair<pair<int, string>, int> &a, pair<pair<int, string>, int> &b) {
    if (a.first.first == b.first.first) return a.first.second < b.first.second;
    else return a.first.first < b.first.first;
}

char ss[300];

int main() {
    while (1) {
        vector<pair<pair<int, string>, int>> v;
        vector<int> ans;
        bool valid = true;
        while (1) {
            if (scanf("%s", ss) != 1) exit(0);
            if (ss[0] == '(' && ss[1] == ')') {
                valid = false;
                break;
            }
            int num;
            string pos;
            string curr = "";
            bool f = true;
            for (int i = 1; i < 300; ++i) {
                if (ss[i] != ',' && f) {
                    curr.push_back(ss[i]);
                } else if (ss[i] == ',') {
                    f = false;
                } else if (ss[i] != ',' && !f && ss[i] == 76 || ss[i] == 82) {
                    pos.push_back(ss[i]);
                }
                if(ss[i] == ')') break;
            }
            num = stoi(curr);
            v.push_back({{len(pos), pos}, num});
        }
        sort(all(v), comp);

        int f = 0;
        for (int i = 0; i < len(v); ++i) {
            string tem = v[i].first.second;
            if(tem != "")
            tem.pop_back();
            if (check(v, tem, v[i].first.second)) {
                ans.push_back(v[i].second);
            } else {
                cout << "not complete" << nline;
                f = 1;
                break;
            }
        }
        if (!f) {
            for (int i = 0; i < len(ans); ++i) {
                cout << ans[i] << (i == len(ans) - 1 ? "\n" : " ");
            }
        }
    }
}
