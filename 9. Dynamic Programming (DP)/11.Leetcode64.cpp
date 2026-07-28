class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (i<0 || j<0)
            return INT_MAX;
        if (i==0 && j==0)
            return grid[0][0];

        if (memo[i][j] != -1)
            return memo[i][j];
        int up = solve(i-1, j, grid, memo);
        int left = solve(i, j-1, grid, memo);
        return memo[i][j] = grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, memo);
    }
};