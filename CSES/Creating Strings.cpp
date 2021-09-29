// https://cses.fi/problemset/task/1622/

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define forl(i, a, n) for(int i = a; i < n; i++)
#define forn(i, a, n) for(int i = a; i <= ; i++)
#define all(x) (x).begin(), (x).end()
#define len(x) (int)x.size()
typedef long long ll;
typedef unsigned int uit;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define newline "\n"
#define fir first
#define sec second
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
 
void IO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
 
 
int main() {
    IO();
    string s; cin >> s;
    vector<string> v;
    sort(all(s));
    do{
        v.pb(s);
    }while(next_permutation(all(s)));
    cout <<  v.size() << newline;
    forl(i, 0, v.size())
        cout << v[i] << newline;
}
