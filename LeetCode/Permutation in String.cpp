// https://leetcode.com/problems/permutation-in-string/description/

bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size()) return false;
    vector<int> freq(26);
    for (int i = 0; i < s1.size(); ++i) freq[s1[i] - 'a']++;
    for (int i = 0; i <= s2.size() - s1.size(); ++i) {
        vector<int> tem = freq;
        int valid = 1;
        for (int j = i; j < s1.size() + i; ++j) {
            tem[s2[j] - 'a']--;
        }
        for (int j = 0; j < 26; ++j) {
            if(tem[j] != 0) {
                valid = 0;
                break;
            }
        }
        if(valid) return true;
    }
    return false;
}
