// https://leetcode.com/problems/reverse-integer/

#include <bits/stdc++.h>

class Solution {
public:
    int reverse(int x) {
        int neg = 0;
        long long n = x, ans = 0;
        if(n < 0) neg = 1, n *= -1;
        while(n){
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        if(neg) ans *= -1;
        if(ans >= -2147483648 && ans <= 2147483647) return ans;
        return 0;
    }
};
