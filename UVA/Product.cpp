//https://vjudge.net/problem/UVA-10106

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
const double PI = 2 * asin(1);
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
int main() {
    //IO();
    string s, t;
    while(cin >> s >> t) {
        vector<int> v(600);
 
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
 
        for (int i = 0; i < (int)s.size(); ++i)
            for (int j = 0; j < (int)t.size(); ++j)
                v[i + j] += (s[i] - '0') * (t[j] - '0');
 
        while (v.back() == 0 && !v.empty()) v.pop_back();
        for (int i = 0; i < (int)v.size() - 1; ++i) {
            v[i + 1] += v[i] / 10;
            v[i] %= 10;
        }
        for (int i = (int)v.size() - 1; i >= 0 ; --i) cout << v[i];
        if(v.empty()) cout << "0";
        cout << endl;
    }
    return 0;
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
