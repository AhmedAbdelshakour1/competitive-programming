// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a882

#include <bits/stdc++.h>

using namespace std;
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main() {
    IO();
    int t; cin >> t;
    for(int test = 1; test <= t; test++){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> cnt(n + 1);
        cnt[1] = 1;
        for(int i = 1; i < n; i++){
            if(s[i] > s[i - 1]) cnt[i + 1] += cnt[i] + 1;
            else cnt[i + 1]++;
        }
        cout << "Case #" << test << ": ";
        for(int i = 1; i <= n; i++) cout << cnt[i] << " ";
        cout << "\n";
    }
}
