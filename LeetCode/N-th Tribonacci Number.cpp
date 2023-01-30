// https://leetcode.com/problems/n-th-tribonacci-number/description/

    int tribonacci(int n) {
        int a = 0, b = 1, c = 1, ans = 2;
        if(n == 0) return a;
        if(n == 1) return b;
        if(n == 2) return c;
        if(n == 3) return ans;
        for(int i = 4; i <= n; i++){
            a = b;
            b = c;
            c = ans;
            ans = a + b + c;
        }
        return ans;
    }
