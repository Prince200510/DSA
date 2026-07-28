class Solution {
public:
    bool bfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& visited) {
        int n = grid1.size();
        int m = grid1[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = 1;
        bool is_sub = true;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(grid1[x][y] == 0) {
                is_sub = false;
            }
            for(int i = 0; i < 4; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid2[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return is_sub;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n1 = grid1.size();
        int m1 = grid1[0].size();

        vector<vector<int>> visited(n1, vector<int>(m1, 0));

        int count = 0;
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < m1; j++) {
                if(grid2[i][j] == 1 && !visited[i][j]) {
                    if(bfs(i, j, grid1, grid2, visited)) {
                        count++;
                    }
                    // count++;
                }
            }
        }

        return count;
    }
};