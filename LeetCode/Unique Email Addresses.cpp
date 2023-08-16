// https://leetcode.com/problems/unique-email-addresses/description/

class Solution {
public:
    string getDomainName(string email){
        string s;
        for(int i = email.size() - 1; ~i; i--){
            if(email[i] == '@') break;
            s.push_back(email[i]);
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int numUniqueEmails(vector<string>& emails) {
        set<string> ans;
        for(auto &email : emails){
            string curr;
            for(int i = 0; i < email.size(); i++){
                if(email[i] == '@' || email[i] == '+') break;
                if(email[i] == '.') continue;
                curr.push_back(email[i]);
            }
            curr.push_back('@');
            curr += getDomainName(email);
            ans.insert(curr);
        }
         return (int)ans.size();
    }
};
