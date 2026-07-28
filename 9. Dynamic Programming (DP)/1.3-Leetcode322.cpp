class Solution {
public:
    vector<int> memo;

    int helper(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;

        if (memo[amount] != -1)
            return memo[amount];

        int ans = INT_MAX;
        for (int coin : coins) {
            int res = helper(coins, amount - coin);
            if (res != INT_MAX)
                ans = min(ans, 1 + res);
        }
        return memo[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount + 1, -1);
        int res = helper(coins, amount);
        return (res == INT_MAX) ? -1 : res;
    }
};