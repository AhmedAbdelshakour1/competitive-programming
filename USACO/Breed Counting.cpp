// http://www.usaco.org/index.php?page=viewproblem2&cpid=572

/// You just can't beat the person who never gives up.
#include <bits/stdc++.h>
 
using namespace std;
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
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    IO();
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<ll> count1(n + 1);
    vector<ll> count2(n + 1);
    vector<ll> count3(n + 1);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 1; i < n + 1; i++){
        count1[i] = (v[i - 1] == 1) + count1[i - 1];
        count2[i] = (v[i - 1] == 2) + count2[i - 1];
        count3[i] = (v[i - 1] == 3) + count3[i - 1];
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << count1[b] - count1[a - 1] << " " << count2[b] - count2[a - 1] << " " << count3[b] - count3[a - 1] << newline;
    }
}
