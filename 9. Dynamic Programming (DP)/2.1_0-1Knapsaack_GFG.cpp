class Solution {
  public:
    int maxVal(int W, vector<int>& val, vector<int>& wt, int idx, vector<vector<int>>& memo) {
        if (idx >= val.size() || W == 0)
            return 0;
            
        if (memo[idx][W] != -1)
            return memo[idx][W];
            
        int notPick = maxVal(W, val, wt, idx+1, memo);
        int pick = 0;
        if (wt[idx] <= W)
            pick = maxVal(W-wt[idx], val, wt, idx+1, memo) + val[idx];
        return memo[idx][W] = max(pick, notPick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> memo(val.size(), vector<int>(W+1, -1));
        return maxVal(W, val, wt, 0, memo);
    }
};