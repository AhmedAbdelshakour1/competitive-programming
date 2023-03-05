// https://leetcode.com/problems/jump-game-iv/description/

class Solution {
public:
unordered_map<int, vector<int>> mp;
int ans = 0;
int bfs(int n, vector<int> &v){
    vector<int> vis(n);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int currIndx = q.front();
            if(currIndx == n - 1) return ans;
            q.pop();
            if (currIndx + 1 < n && !vis[currIndx + 1]) q.push(currIndx + 1), vis[currIndx + 1] = 1;
            if (currIndx - 1 >= 0 && !vis[currIndx - 1]) q.push(currIndx - 1), vis[currIndx - 1] = 1;
            for (int x: mp[v[currIndx]]) {
                if (!vis[x]) q.push(x), vis[x] = 1;
            }
            mp[v[currIndx]].clear();
        }
        ans++;
    }
    return 0;
}
int minJumps(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        mp[arr[i]].push_back(i);

   return bfs(arr.size(), arr);
}
};
