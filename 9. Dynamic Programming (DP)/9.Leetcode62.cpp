class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 0));
        return countWays(0 , 0, m, n, memo);
    }

private:
    int countWays(int x, int y, int m, int n, vector<vector<int>>& memo) {
        if (x == m-1 && y == n-1)
            return 1;

        if (x >= m || y >= n)
            return 0;

        if (memo[x][y] != 0)
            return memo[x][y];

        int right = countWays(x, y+1, m, n, memo);
        int bottom = countWays(x+1, y, m, n, memo);
        return memo[x][y] = right + bottom;
    }
};