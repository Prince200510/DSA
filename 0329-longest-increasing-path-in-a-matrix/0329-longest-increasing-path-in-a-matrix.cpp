class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int n = mat.size();
        int m = mat[0].size();
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        int ans = 1;

        for(int k = 0; k < 4; k++) {
            int nx = i + dr[k];
            int ny = j + dc[k];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] > mat[i][j]) {
                ans = max(ans, 1 + dfs(nx, ny, mat, dp));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }

        return ans;
    }
};