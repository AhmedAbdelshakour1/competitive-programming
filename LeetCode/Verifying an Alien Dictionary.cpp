// https://leetcode.com/problems/verifying-an-alien-dictionary/description/

int cnt[26];
bool valid(string &a, string &b){
    for (int i = 0; i < min(a.size(), b.size()); ++i) {
        if(cnt[a[i] - 'a'] < cnt[b[i] - 'a']) return true;
        if(cnt[a[i] - 'a'] > cnt[b[i] - 'a']) return false;
    }
    return a.size() <= b.size();
}
bool isAlienSorted(vector<string>& words, string order) {
    for (int i = 0; i < 26; ++i) cnt[order[i] - 'a'] = i;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            if(!valid(words[i], words[j])) return false;
        }
    }
    return true;
}
