class Solution {
public:
    bool safe (int& n, int& row, int& col, vector<vector<int>>& board) {
        for (int r = 0; r < row; r++) {
            if (board[r][col] == 1)
                return false;
        }

        int r = row - 1, c = col - 1;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 1)
                return false;
            r--;
            c--;
        }

        r = row - 1; c = col + 1;
        while (r >= 0 && c < n) {
            if (board[r][c] == 1)
                return false;
            r--;
            c++;
        }

        return true;
    }

    int solve (int& n, int row, vector<vector<int>>& board) {
        if (row == n)
            return 1;
        
        int ways = 0;
        for (int col = 0; col < n; col++) {
            if (safe(n, row, col, board)) {
                board[row][col] = 1;

                int count = solve(n, row+1, board);
                if (count != 0)
                    ways += count;
                else
                    board[row][col] = 0;
            }
            board[row][col] = 0;
        }
        return ways;
    }

    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        return solve(n, 0, board);
    }
};