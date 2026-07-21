class Solution {
public:
    pair<int, int> get_pos(int num, int n) {
        int row = (num - 1) / n;
        int col = (num - 1) % n;

        if(row % 2 == 1) {
            col = n - 1 - col;
        }

        row = n - 1 - row;

        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        vector<bool> visited(n * n + 1, false);

        q.push({1, 0});
        visited[1] = true;

        while(!q.empty()) {
            int curr = q.front().first;
            int mov = q.front().second;
            q.pop();

            if(curr == n * n) {
                return mov;
            }

            for(int i = 1; i <= 6 && curr + i <= n * n; i++) {
                int next = curr + i;
                auto [r, c] = get_pos(next, n);

                if(board[r][c] != -1) {
                    next = board[r][c];
                }

                if(!visited[next]) {
                    visited[next] = true;
                    q.push({next, mov + 1});
                }
            }
        }

        return -1;
    }
};