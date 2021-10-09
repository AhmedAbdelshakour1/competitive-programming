// http://www.usaco.org/index.php?page=viewproblem2&cpid=1035

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
int largestGap(string st, int &sGap){
    int biggest = 0, currS = -1;
    for(int i = 0; i < st.size(); i++){
        if(st[i] == '1'){
            if(currS != -1 && i - currS > biggest){
                biggest = i - currS;
                sGap = currS;
            }
            currS = i;
        }
    }
    return biggest;
}
int smallestD(string st){
    int dis = 1000000000, currS = -1;
    for(int i = 0; i < st.size(); i++){
        if(st[i] == '1'){
            if(currS != -1 && i - currS < dis) dis = i - currS;
            currS = i;
        }
    }
    return dis;
}
int tryInLargeGap(string st){
    int gap, large = largestGap(st, gap);
    if(large >= 2){
        st[gap + large / 2] = '1';
        return smallestD(st);
    }
    return -1;
}
int main(){
    IO();
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int n, ans = 0;
    string s, temp;
    cin >> n >> s;
    int startGap, larGap = largestGap(s, startGap);
    if(larGap >= 3){
         temp = s;
        temp[startGap + larGap / 3] = '1';
        temp[startGap + larGap * 2 / 3] = '1';
        ans = max(ans, smallestD(temp));
    }
    if(s[0] == '0' && s[n - 1] == '0'){
         temp = s;
         temp[0] = '1';
         temp[n - 1] = '1';
         ans = max(ans, smallestD(temp));
    }
    if(s[0] == '0'){
        temp = s;
        temp[0] = '1';
        ans = max(ans, tryInLargeGap(temp));
    }
    if(s[n - 1] == '0'){
        temp = s;
        temp[n - 1] = '1';
        ans = max(ans, tryInLargeGap(temp));
    }
    if(larGap >= 2){
        temp = s;
        temp[startGap + larGap / 2] = '1';
        ans = max(ans, tryInLargeGap(temp));
    }
    cout << ans << newline;
}
