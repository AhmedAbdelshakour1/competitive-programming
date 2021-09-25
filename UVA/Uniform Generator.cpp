// https://vjudge.net/problem/UVA-408

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
    int step, mod;
    while(cin >> step >> mod){
        bool bad = false;
        set<int> v;
        int r = 0;
        for(int i = 0; i < mod; i++){
            r = (r + step) % mod;
            v.insert(r);
        }
        if(v.size() != mod){
            cout << setw(10) << step << setw(10) << mod << "    " << "Bad Choice\n\n";
            continue;
        }
        auto it = v.begin();
        for (int j = 0; j < mod; ++j) {
            if(*it != j){
                cout << setw(10) << step << setw(10) << mod << "    " << "Bad Choice\n\n";
                bad = true;
                break;
            }
            it++;
        }
        if(!bad)
            cout << setw(10) << step << setw(10) << mod << "    " << "Good Choice\n\n";
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
