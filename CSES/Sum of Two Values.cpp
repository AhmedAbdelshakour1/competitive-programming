// https://cses.fi/problemset/task/1640/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
   int n, x;
   scanf("%d %d", &n, &x);
   int a[n];
   map<int, int> m;
   for(int i = 0; i < n; i++){
       scanf("%d", &a[i]);
       m[a[i]] = i + 1;
   }
   for(int i = 0; i < n; i++){
       int y = x - a[i];
       if(m.count(y) && m[y] != i + 1) {
           cout << i + 1 << " " << m[y];
           return 0;
       }
   }
   cout << "IMPOSSIBLE";
}
