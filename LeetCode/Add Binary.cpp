// https://leetcode.com/problems/add-binary/description/

string addBinary(string a, string b) {
    int n = a.size() - 1, m = b.size() - 1, carry = 0;
    string ans = "";
    while(~n || ~m || carry){
        if(n >= 0) carry += a[n--] - '0';
        if(m >= 0) carry += b[m--] - '0';
        ans += carry % 2 + '0';
        carry /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
