class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        return lcs(text1, text2, 0, 0, memo);
    }
private:
    int lcs(string& s, string& t, int i, int j, vector<vector<int>>& memo) {
        if (i == s.size() || j == t.size())
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s[i] == t[j])
            return memo[i][j] = 1 + lcs(s, t, i+1, j+1, memo);
        return memo[i][j] = max(lcs(s, t, i+1, j, memo), lcs(s, t, i, j+1, memo));
    }
};