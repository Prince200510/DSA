class Solution {
public:
    int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        int area = 0;
        queue<pair<int, int>> q;
        visited[r][c] = 1;
        q.push({r,c});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            area++;

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    //grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    ans = max(ans, bfs(i, j, grid, visited));
                }
            }
        }

        return ans;
    }
};