class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e8);
        dist[src] = 0;

        // relax
        for(int i = 0; i <= k; i++) {
            vector<int> temp = dist;

            for(auto& e : flights) {
                int u = e[0];
                int v = e[1];
                int wt = e[2];

                if(dist[u] != 1e8 && dist[u] + wt < temp[v]) {
                    // if(i == n - 1) {
                    //     return {-1};
                    // }

                    temp[v] = dist[u] + wt;
                }
            }

            dist = temp;
        }

        return dist[dst] == 1e8 ? -1 : dist[dst];
    }
};