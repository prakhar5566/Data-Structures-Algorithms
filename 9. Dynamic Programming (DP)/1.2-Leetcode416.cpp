class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int e : nums)
            sum += e;

        if (sum % 2 != 0)
            return false;

        sum /= 2;
        vector<vector<int>> memo(nums.size(), vector<int>(sum + 1, -1));
        return dp(nums, sum, 0, memo);
    }

private:
    bool dp(vector<int>& nums, int target, int idx, vector<vector<int>>& memo) {
        if (target == 0)
            return true;

        if (idx == nums.size() || target < 0)
            return false;

        if (memo[idx][target] != -1)
            return memo[idx][target] == 1;
        bool notPick = dp(nums, target, idx + 1, memo);
        bool pick = dp(nums, target - nums[idx], idx + 1, memo);

        memo[idx][target] = (pick || notPick) ? 1 : 0;
        return memo[idx][target] == 1;
    }
};