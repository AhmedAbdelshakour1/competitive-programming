// https://cses.fi/problemset/task/1068/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long long int lli;
typedef unsigned long long int ulli;
 
int main() {
    ll x;
    scanf("%lld", &x);
    cout << x << " ";
    while(x > 1){
        if(x % 2 == 0) {
            x /= 2;
            cout << x << " ";
        }
        else{
            x = x * 3  + 1;
            cout << x << " ";
        }
    }
}
