// https://cses.fi/problemset/task/2205?fbclid=IwAR0y1NWoXG9yfCH0atFCk7Mk-HUIHp_1jadil_2cZucEBBE5UfaGP089s7w

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
unordered_set<string> st;
int main() {
    int n; cin >> n;
    int possible = 1 << n;
    string s = "";
    for(int i = 0; i < n; i++){
        cout << "0";
        s += "0";
    }
    cout << endl;
    st.insert(s);
    for (int i = 0; i < possible; ++i) {
        string curr = s;
        for(int j = 0; j < n;j++){
            // do
            if(curr[j] == '0') curr[j] = '1';
            else curr[j] = '0';
            if(!st.count(curr)){
                s = curr;
                cout << s << endl;
                st.insert(s);
                break;
            }
            //undo
            if(curr[j] == '0') curr[j] = '1';
            else curr[j] = '0';
        }
    }
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
