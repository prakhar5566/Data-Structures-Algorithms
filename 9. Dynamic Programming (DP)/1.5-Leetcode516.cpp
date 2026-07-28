class Solution {
public:
    vector<vector<int>> memo;

    int helper(string &s, int l, int r) {
        if (l > r)
            return 0;
        if (l == r)
            return 1;

        if (memo[l][r] != -1)
            return memo[l][r];

        if (s[l] == s[r])
            return memo[l][r] = 2 + helper(s, l+1, r-1);
        else
            return memo[l][r] = max(helper(s, l+1, r), helper(s, l, r-1));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memo.assign(n, vector<int>(n, -1));
        return helper(s, 0, n-1);
    }
};