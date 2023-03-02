// https://leetcode.com/problems/string-compression/description/

class Solution {
public:
void calc(int curr, char x, string &s, int &ans){
    string tem;
    s += x;
    tem = to_string(curr);
    ans++;
    if(curr > 1){
        s += tem;
        ans += tem.size();
    }
}
int compress(vector<char>& chars) {
    int ans = 0, curr = 1;
    char x = chars[0];
    string s = "", tem = "";
    for(int i = 1; i < chars.size(); i++){
        if(chars[i] == x) curr++;
        else {
            calc(curr, x, s, ans);
            curr = 1;
            x = chars[i];
        }
    }
    calc(curr, x, s, ans);
    for (int i = 0; i < s.size(); ++i) {
        chars[i] = s[i];
    }
    return ans;
}

};
