// https://leetcode.com/problems/counting-bits/description/

// by using dp -> O(n)
vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    ans[0] = 0;
    for (int i = 1; i <= n; ++i) {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
}

// by using __builtin_popcount() function -> O(n)
vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    for(int i = 0; i <= n; i++) ans[i] = __builtin_popcount(i);
    return ans;
}

// without using __builtin_popcount() function -> O(n * log(n))
vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    for(int i = 0; i <= n; i++) {
        int cnt = 0;
        int x = i;
        while(x) {
            cnt += (x & 1);
            x >>= 1;
        }
    }
    return ans;
}
