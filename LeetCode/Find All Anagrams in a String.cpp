// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

vector<int> findAnagrams(string s, string p) {
    int n = s.size(), m = p.size();
    if(m > n) return {};
    vector<int> ans, freqP(26), freqS(26);
    for (int i = 0; i < m; ++i) freqP[p[i] - 'a']++, freqS[s[i] - 'a']++;
    if(freqP == freqS) ans.push_back(0);
    for (int i = m; i < n; ++i) {
        freqS[s[i] - 'a']++;
        freqS[s[i - p.size()] - 'a']--;
        if(freqS == freqP) ans.push_back(i - m + 1);
    }
    return ans;
}
