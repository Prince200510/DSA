class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        queue<int> q;
        vector<int> visited(n + 1, 0);
        q.push(1);
        visited[1] = 1;
        int ans = INT_MAX;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {
                int next = it.first;
                int wt = it.second;

                ans = min(ans, wt);

                if(!visited[next]) {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
        return ans;
    }
};