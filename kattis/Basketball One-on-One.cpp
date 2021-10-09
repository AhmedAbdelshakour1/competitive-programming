// https://open.kattis.com/contests/mcpc19open/problems/basketballoneonone

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long long int lli;
typedef unsigned long long int ulli;
int main(){
    //freopen("paint.in", "r", stdin);
    //freopen("paint.out", "w", stdout);
    string s;
    getline(cin, s);
    int cA = 0, cB = 0;
    for(int i = 0; i < s.length(); i += 2){
        if(s[i] == 'A') cA += s[i + 1];
        else cB += s[i + 1];
    }
    if(cA > cB) printf("%c", 'A');
    else printf("%c", 'B');
}
