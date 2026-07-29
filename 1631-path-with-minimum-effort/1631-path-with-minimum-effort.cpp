class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int effort = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if(r == m - 1 && c == n - 1) {
                return effort;
            }

            if(effort > dist[r][c]) {
                continue;
            }

            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int new_effort = max(effort, abs(heights[r][c] - heights[nr][nc]));
                    
                    if(new_effort < dist[nr][nc]) {
                        dist[nr][nc] = new_effort;
                        pq.push({new_effort, {nr, nc}});
                    }
                }  
            }
        }
        return 0;
    }
};