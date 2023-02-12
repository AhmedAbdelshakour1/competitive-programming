// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

const static int N = 105;
vector<pair<int, int>> adj[N];
vector<vector<int>> dis;
void bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    dis[0][0] = 0;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        for(auto child : adj[curr.first]){
            if(child.second == curr.second) continue;
            if(dis[child.first][child.second] == 1e9) {
                dis[child.first][child.second] = dis[curr.first][curr.second] + 1;
                q.push({child.first, child.second});
            }
        }
    }
}
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    for (auto & redEdge : redEdges)
        adj[redEdge[0]].push_back({redEdge[1], 1});

    for (auto & blueEdge : blueEdges)
        adj[blueEdge[0]].push_back({blueEdge[1], 2});
    dis.resize(n, vector<int> (3, 1e9));
    bfs();
    vector<int> ans(n, 0);
    for(int i = 1; i < n; i++){
        ans[i] = min(dis[i][1], dis[i][2]);
        if(ans[i] == 1e9) ans[i] = -1;
    }
    return ans;
}
