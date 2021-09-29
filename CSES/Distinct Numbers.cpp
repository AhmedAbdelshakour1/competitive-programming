// https://cses.fi/problemset/task/1621/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long long int lli;
typedef unsigned long long int ulli;
 
int main() {
    int x;
    //freopen("square.in", "r", stdin);
    //freopen("square.out", "w", stdout);
    scanf("%d", &x);
    set<int> st;
    int a[x];
    for(int i = 0; i < x; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    printf("%d", st.size());
}
