// https://vjudge.net/problem/UVA-10815

#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define nl '\n'
#define rv return void
#define len(x) int((x).size())
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {0, 0, -1, 1};

const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const int INF = (int) 2e9 + 10;
const ll OO = 1e18;
const double eps = 1e-9;

void IO(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}

int dcomp(double a, double b) { return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1; }

bool isPowerOfTwo(ll n) { return n && (!(n & (n - 1))); }

ll bPow(ll a, ll p) {
    ll result = 1;
    while (p) {
        if (p & 1) result *= a;
        a *= a;
        p >>= 1;
    }
    return result;
}

//..................................................................................//

void solve() {
    string s;
    set<string> st;
    while(getline(cin, s)){
        transform(all(s), s.begin(), ::tolower);
        string word;
        for(auto &i : s){
            if(isalpha(i))
                word += i;
            else if(!word.empty()){
                st.insert(word);
                word.clear();
            }
        }
        if(!word.empty())
            st.insert(word);
    }
    for(auto &word : st)
        cout << word << nl;
}

int main() {
    IO();
    int tc = 1;
//    cin >> tc;
    while (tc--)
        solve();
}










