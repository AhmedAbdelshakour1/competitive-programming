// https://cses.fi/problemset/task/1652/

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
typedef long long ll;
 
int main() {
    IO();
    int n, q;
    cin >> n >> q;
    int arr[n + 1][n + 1] = {};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char a;
            cin >> a;
            if(a == '*') arr[i][j]++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= q; i++){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1] << "\n";
        }
}
 
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
     No idea is a BAD idea!
     NEVER to assume something not mentioned!
     Thinking Concretely, Symbolically, Pictorically..
     Think in the smallest boundaries (e.g. n = 0, 1, 2 - R*C = {1*1, 1*2, 2*1, 2, 2} - str = "", str = "a", ...)
     Think in the largest boundaries (e.g. n = MAX, array is fully, string has max characters, ...)
     Think in especial cases (array filled with zeros, 1 1 1 1, .....)
     Make sure that you know exactly what is output and its "format"
 */
