// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/

// Backtracking Solution
class Solution {
public:
    vector<string> ans;
    void generate(string curr, int n){
        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(curr.size() && curr.back() == ch) continue;
            generate(curr + ch, n);
        }
        return;
    }
    string getHappyString(int n, int k) {
        // Total number of strings equal 3 * 2^(n - 1) => 3 * 2^99
        if(3 * pow(2, n - 1) < k) return "";
        generate("", n);
        return ans[k - 1];
    }
};

// Iterative Using a Stack
class Solution {
public:
    string getHappyString(int n, int k) {
        int numberOfSortedStrings = 0;
        stack<string> st;
        st.push("");
        while(st.size()){
            string currString = st.top();
            st.pop();
            if(currString.size() == n){
                numberOfSortedStrings++;
                if(numberOfSortedStrings == k) return currString;
                continue;
            }
            for(char ch = 'c'; ch >= 'a'; ch--){
                if(currString.size() && currString.back() == ch) continue;
                st.push(currString + ch);
            }
        }
        return "";
    }
};
