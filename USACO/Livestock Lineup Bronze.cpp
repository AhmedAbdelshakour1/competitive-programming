// http://www.usaco.org/index.php?page=viewproblem2&cpid=965

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
vector<string> v = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
int wordPlace(string s){
    int i;
    for(i = 0; i < v.size(); i++){
        if(v[i] == s) return i;
    }
}
int main() {
    IO();
    freopen ("lineup.in","r",stdin);
    freopen ("lineup.out","w",stdout);
    int n; cin >> n;
    string t;
    vector<pair<string, string>> a(n);
    for(auto &i : a)
        cin >> i.fir >> t >> t >> t >> t >> i.sec;
 
    sort(all(v));
    do{
        bool flag = true;
        forl(i, 0, n){
            if(abs(wordPlace(a[i].fir) - wordPlace(a[i].sec)) != 1)
                flag  = false;
        }
        if(flag) break;
    }while(next_permutation(all(v)));
 
    for(auto i : v)
        cout << i << newline;
}
