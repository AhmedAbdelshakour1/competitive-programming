// https://leetcode.com/problems/as-far-from-land-as-possible/description/

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<pair<int, int>> water, land;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!grid[i][j]) water.push_back({i, j});
            else land.push_back({i, j});
        }
    }
    int ans = -1;
    if(water.size() == n * n || land.size() == n * n){
        return ans;
    }
    for(auto &x : water){
        int res = 1e9;
        for(auto &y : land) res = min(res, abs(x.first - y.first) + abs(x.second - y.second));
        ans = max(ans, res);
    }
    return ans;
}

// Another Solutin: multi-source BFS
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {0, 0, -1, 1};
int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j]) q.push({i, j});

    if(q.empty() || q.size() == n * n) return -1;
    int ans = -1;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int moveX = x + dx4[i];
                int moveY = y + dy4[i];
                if(moveX >= 0 && moveX < n && moveY >= 0 && moveY < n && !grid[moveX][moveY]){
                    grid[moveX][moveY] = 1;
                    q.push({moveX, moveY});
                }
            }
        }
        ans++;
    }
    return ans;
}
