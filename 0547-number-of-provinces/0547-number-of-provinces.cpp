class Solution {
public:
    void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int i = 0; i < adj.size(); i++) {
                if(adj[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n ,false);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                count++;
                bfs(i, isConnected, visited);
                // count++;
            }
        }
        return count;
    }
};