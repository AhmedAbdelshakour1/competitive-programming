// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

long long ans = 0;
vector<vector<int>> adj;
int dfs(int node, int parent, int seats){
    int people = 1;
    for(int child : adj[node]){
        if(child != parent) people += dfs(child, node, seats);
    }
    if(node) ans += (people + seats - 1) / seats;
    return people;
}
long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    adj.resize(roads.size() + 1);
    for (int i = 0; i < roads.size(); ++i) {
        adj[roads[i][0]].push_back(roads[i][1]);
        adj[roads[i][1]].push_back(roads[i][0]);
    }
    dfs(0, -1, seats);
    return ans;
}
