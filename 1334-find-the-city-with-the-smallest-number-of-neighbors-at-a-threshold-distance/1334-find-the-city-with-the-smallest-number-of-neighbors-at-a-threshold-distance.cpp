class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int INF = 1e8;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            // dist[u].push_back({v, wt});
            // dist[v].push_back({u, wt});
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] != INF && dist[k][j]) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int ans = -1;
        int min_count = INT_MAX;    

        for(int i = 0; i < n; i++) {
            int count = 0;

            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            if(count <= min_count) {
                min_count = count;
                ans = i;
            }
        }
        return ans;
    }
};