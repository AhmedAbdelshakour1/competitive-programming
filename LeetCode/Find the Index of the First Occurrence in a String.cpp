// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

// Another Solution
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int currIndx = 0;
        for(int i = 0; i < n; i++){
            if(haystack[i] == needle[currIndx]) currIndx++;
            else i -= currIndx, currIndx = 0;
            if(currIndx == m) return i + 1 - currIndx;
        }
        return -1;
    }
};
