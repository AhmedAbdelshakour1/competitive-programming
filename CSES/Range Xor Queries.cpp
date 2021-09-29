// https://cses.fi/problemset/task/1650/

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
 
 
int main() {
    int n, q; cin >> n >> q;
    vector<int> arr(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) arr[i] = (arr[i] ^ arr[i - 1]);
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        cout << (arr[b] ^ arr[a - 1]) << newline;
    }
 
}
