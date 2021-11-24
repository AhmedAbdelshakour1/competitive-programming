// https://cses.fi/problemset/task/1755/

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
int cnt[26];
int main() {
    string s; cin >> s;
    int n = len(s);
    for(int i = 0; i < n; i++) cnt[s[i] - 'A']++;
    int c = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i] & 1) c++;
    }
    if(c > 1){
        cout << "NO SOLUTION";
        return 0;
    }
    deque<char> ans;
    for(int i = 0; i < 26; i++){
        if(cnt[i] & 1){
            for(int j = 0; j < cnt[i]; j++) ans.push_back(char(i + 'A'));
        }
    }
    for(int i = 0; i < 26; i++) {
        if (!(cnt[i] & 1)) {
            for (int j = 0; j < cnt[i] / 2; j++) ans.push_back(char(i + 'A'));
            for (int j = cnt[i] / 2; j < cnt[i]; j++) ans.push_front(char(i + 'A'));
        }
    }
    for(char &curr : ans) cout << curr;
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
