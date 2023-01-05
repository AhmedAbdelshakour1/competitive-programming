// https://leetcode.com/problems/valid-parentheses/description/

//...............................C#........................................//
public class Solution {
    public bool IsValid(string s) {
        Stack<char> st = new Stack<char>();
        for (int i = 0; i < s.Length; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.Push(s[i]);
            else {
                if (st.Count > 0 && (st.Peek() == '(' && s[i] != ')' || st.Peek() == '[' && s[i] != ']' ||
                                     st.Peek() == '{' && s[i] != '}') || st.Count == 0) {
                    return false;
                }
                st.Pop();
            }
        }
        return st.Count == 0;
    }
}

//...............................Cpp........................................//

class Solution {
public:
bool isValid(string s) {
    int n = s.size();
    stack<char> st;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
        else {
            if(!st.empty() && (st.top() == '(' && s[i] != ')' || st.top() == '[' && s[i] != ']' || st.top() == '{' && s[i] != '}') || st.empty()) {
                ok = false;
                break;
            } else st.pop();
        }
    }
    return ok && st.empty();
  }
};
