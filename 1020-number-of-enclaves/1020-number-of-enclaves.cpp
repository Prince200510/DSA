class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][0] == 1) {
                    q.push({i, 0});
                    grid[i][0] = 0;
                }

                if(grid[i][m - 1] == 1) {
                    q.push({i, m - 1});
                    grid[i][m - 1] = 0;
                }
            }
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }
            if(grid[n - 1][j] == 1) {
                q.push({n - 1, j});
                grid[n - 1][j] = 0;
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = x + dr[i];
                int nc = y + dc[i];

                if(nr >= 0 & nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};