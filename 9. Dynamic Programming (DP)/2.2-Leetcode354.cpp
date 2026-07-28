class Solution {
public:
    int helper(vector<vector<int>>& envelopes, int idx, int prev, vector<vector<int>>& memo) {
        if (idx >= envelopes.size())
            return 0;

        if (memo[idx][prev+1] != -1)
            return memo[idx][prev+1];

        int pick = 0;
        if (prev == -1 || (envelopes[idx][0]>envelopes[prev][0] && envelopes[idx][1]>envelopes[prev][1]))
            pick = helper(envelopes, idx+1, idx, memo) + 1;
        int notPick = helper(envelopes, idx+1, prev, memo);

        return memo[idx][prev+1] = max(pick, notPick);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = envelopes.size();
        vector<vector<int>> memo(n, vector<int>(n+1, -1));
        return helper(envelopes, 0, -1, memo);
    }
};