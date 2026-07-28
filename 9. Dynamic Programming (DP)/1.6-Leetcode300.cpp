class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return lis(nums, 0, -1, dp);
    }

    int lis(vector<int>& nums, int idx, int prev, vector<vector<int>>& dp) {
        if (idx == nums.size())
            return 0;

        if (dp[idx][prev+1] != -1)
            return dp[idx][prev+1];

        int notPick = lis(nums, idx+1, prev, dp);
        int pick=0;
        if (prev == -1 || nums[idx] > nums[prev])
            pick = 1 + lis(nums, idx+1, idx, dp);
        return dp[idx][prev+1] = max(pick, notPick);
    }
};

// patience sorting method in O(nlogn) time
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int x: nums) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if(it == lis.end())
                lis.push_back(x);
            else *it = x;
        }
        return lis.size();
    }
};