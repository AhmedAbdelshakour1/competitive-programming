// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
typedef long long ll;
 
int main() {
    IO();
    int t, n, q;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        ll ans = 0;
        cin >> n >> q;
        vector<ll> v(n + 1), prefix(n + 1), lprefix(n + 1);
        int s = 1;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            prefix[i] = prefix[i - 1] + (s * i * v[i]);
            lprefix[i] = lprefix[i - 1] + (s * v[i]);
            s *= -1;
        }
        char ch;
        int l, r;
        while (q--) {
            cin >> ch >> l >> r;
            if (ch == 'Q') {
                ll cal = (prefix[r] - prefix[l - 1]) - (l - 1) * (lprefix[r] - lprefix[l - 1]);
                if (l & 1) ans += cal;
                else ans -= cal;
            } else {
                v[l] = r;
                int s = 1;
                for (int i = 1; i <= n; i++) {
                    prefix[i] = prefix[i - 1] + s * i * v[i];
                    lprefix[i] = lprefix[i - 1] + s * v[i];
                    s *= -1;
                }
            }
        }
        cout << "Case #" << test << ": " << ans << '\n';
    }
}
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
