class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(n, 0, ans, board);
        return ans;
    }

private:
    void solve (int& n, int row, vector<vector<string>>& ans, vector<string>& board) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (safe(n, row, col, board)) {
                board[row][col] = 'Q';
                solve(n, row+1, ans, board);
            }
            board[row][col] = '.';
        }
    }

    bool safe (int& n, int& row, int& col, vector<string>& board) {
        for (int r = 0; r < row; r++) {
            if (board[r][col] == 'Q')
                return false;
        }

        int r = row - 1, c = col - 1;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        r = row - 1; c = col + 1;
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c++;
        }

        return true;
    }
};