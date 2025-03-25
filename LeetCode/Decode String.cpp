// Recursive Solution

class Solution {
public:
    string solve(deque<char> &dq){
        string ans = "";
        int n = 0;
        while(!dq.empty()){
            char c = dq.front();
            dq.pop_front();
            if(isdigit(c)) n = n * 10 + c - '0';
            else if(c == '['){
                string t = solve(dq);
                while(n--) ans += t;
                n = 0;
            }else if(c == ']') {
                return ans;
            }else ans += c;
        }
        return ans;
    }
    string decodeString(string s) {
        deque<char> dq(s.begin(), s.end());
        return solve(dq);
    }
};

// Stack Solution
class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<string> st;
        int n = s.size(), x = 0;;
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])) x = x * 10 + s[i] - '0';
            else if(s[i] == '['){
                st.push(ans);
                st.push(to_string(x));
                x = 0;
                ans = "";
            }else if(s[i] == ']'){
                int rep = stoi(st.top());
                st.pop();
                string prev = st.top();
                st.pop();
                while(rep--) prev += ans;
                ans = prev;
            }else ans += s[i];
        }
        return ans;
    }
};
