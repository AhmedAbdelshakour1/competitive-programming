// http://www.usaco.org/index.php?page=viewproblem2&cpid=831

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
typedef long long ll;
typedef unsigned int uit;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define fir first
#define sec second
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
 
char ch[3][3];
 
bool check(char ch1, char ch2, char a, char b, char c) {
    // All 3 characters have to be either ch1 or ch2
    if (a != ch1 && a != ch2) return false;
    if (b != ch1 && b != ch2) return false;
    if (c != ch1 && c != ch2) return false;
    // since if we have the a == b == c we get false directly and a, b, c appear at least once each
    // and not more than two...
    if (a != ch1 && b != ch1 && c != ch1) return false;
    if (a != ch2 && b != ch2 && c != ch2) return false;
    return true;
}
 
int team(char c1, char c2) {
    // Check diagonals
    if (check(c1, c2, ch[0][0], ch[1][1], ch[2][2])) return 1;
    if (check(c1, c2, ch[0][2], ch[1][1], ch[2][0])) return 1;
 
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (check(c1, c2, ch[0][i], ch[1][i], ch[2][i])) return 1;
        if (check(c1, c2, ch[i][0], ch[i][1], ch[i][2])) return 1;
    }
 
    return 0;
}
 
int OneCow(char c) {
    //check rows and columns
    rep(i, 0, 3) {
        if (ch[i][0] == c && ch[i][1] == c && ch[i][2] == c) return 1;
        if (ch[0][i] == c && ch[1][i] == c && ch[2][i] == c) return 1;
    }
    // Check diagonals
    if (ch[0][0] == c && ch[1][1] == c && ch[2][2] == c) return 1;
    if (ch[0][2] == c && ch[1][1] == c && ch[2][0] == c) return 1;
 
    return 0;
}
 
int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
 
    int ansOne = 0, ansTeam = 0;
 
    rep(i, 0, 3)rep(j, 0, 3)cin >> ch[i][j];
    for (char c = 'A'; c <= 'Z'; c++) {
        ansOne += OneCow(c);
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        for (char d = c + 1; d <= 'Z'; d++) {
            ansTeam += team(c, d);
        }
    }
 
    cout << ansOne << "\n" << ansTeam;
}
