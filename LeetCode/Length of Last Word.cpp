// https://leetcode.com/problems/length-of-last-word/description/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), sz = 0, found = 0;
        for(int i = n - 1; ~i; --i){
            if(s[i] == ' ') continue;
            while(i >= 0 && s[i] != ' ') sz++, i--;
            break;
        }
        return sz;
    }
};
