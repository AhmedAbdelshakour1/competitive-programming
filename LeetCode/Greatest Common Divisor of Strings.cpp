// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/

bool check(string s, string a){
    for (int i = 0; i < s.size(); i += a.size()) {
        if(s.substr(i, a.size()) != a) return false;
    }
    return true;
}
string gcdOfStrings(string str1, string str2) {
    if(str1.size() < str2.size()) swap(str1, str2);
    string ans = "", tem = "";
    for (int i = 0; i < str2.size(); ++i) {
        tem += str2[i];
        if(str1.size() % tem.size() == 0 && str2.size() % tem.size() == 0){
            if(check(str1, tem) && check(str2, tem)) ans = tem;
        }
    }
    return ans;
}
