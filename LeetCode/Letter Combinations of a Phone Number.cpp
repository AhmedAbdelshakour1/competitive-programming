// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    string s;
    unordered_map<char, string> ump;
    vector<string> ans;
    void rec(int indx, string cur){
        if(indx == s.size()){
            ans.push_back(cur);
            return;
        }
        for(auto &x : ump[s[indx]]){
            rec(indx + 1, cur + x);
        }
    }
    vector<string> letterCombinations(string digits) {
        s = digits;
        ump['2'] = "abc";
        ump['3'] = "def";
        ump['4'] = "ghi";
        ump['5'] = "jkl";
        ump['6'] = "mno";
        ump['7'] = "pqrs";
        ump['8'] = "tuv";
        ump['9'] = "wxyz";
        if(s == "") return ans;
        rec(0, "");
        return ans;
    }
};
