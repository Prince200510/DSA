class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        if(n == 0) return;

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'S';
            }

            if(board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                board[i][m - 1] = 'S';
            }
        } 

        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = 'S';
            }

            if(board[n - 1][j] == 'O') {
                q.push({n - 1, j});
                board[n - 1][j] = 'S';
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

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O') {
                    board[nr][nc] = 'S';
                    q.push({nr, nc});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};