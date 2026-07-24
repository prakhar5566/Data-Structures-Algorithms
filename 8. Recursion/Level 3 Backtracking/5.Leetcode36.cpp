class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rowSet(9), colSet(9), submatrixSet(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';

                if (rowSet[i].count(num))
                    return false;
                rowSet[i].insert(num);

                if (colSet[j].count(num))
                    return false;
                colSet[j].insert(num);

                int boxIndex = (i / 3) * 3 + (j / 3);
                if (submatrixSet[boxIndex].count(num)) return false;
                submatrixSet[boxIndex].insert(num);
            }
        }
        return true;
    }
};

// alternate
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    if (! isValid(board, i, j, board[i][j]))
                        return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int r, int c, char d) {
        for (int i = 0; i < 9; i++) {
            if (i != c && board[r][i] == d)
                return false;
            if (i != r && board[i][c] == d)
                return false;
            int rowIndex = (r/3)*3 + i/3;
            int colIndex = (c/3)*3 + i%3;
            if ((rowIndex != r || colIndex != c) && board[rowIndex][colIndex] == d)
                return false;
        }
        return true;
    }
};