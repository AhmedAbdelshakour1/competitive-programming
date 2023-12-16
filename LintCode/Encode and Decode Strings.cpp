// https://www.lintcode.com/problem/659/

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string  ans = "";
        for(string s : strs){
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> ans;
        int n = str.size();
        int i = 0;
        while(i < n){
            int j = i;
            while(str[j] != '#') j++;
            int len = stoi(str.substr(i, j - i));
            ans.push_back(str.substr(j + 1, len));
            i = j + 1 + len;
        }
        return ans;
    }
};
