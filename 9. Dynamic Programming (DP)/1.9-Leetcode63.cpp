class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (i<0 || j<0 || grid[i][j]==1)
            return 0;
        if (i==0 && j==0)
            return 1;

        if (memo[i][j] != -1)
            return memo[i][j];
        return memo[i][j] = solve(i-1, j, grid, memo) + solve(i, j-1, grid, memo);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(m-1, n-1, obstacleGrid, memo);
    }
};