class Solution {
public:
    bool canSplit(vector<int>& nums, int maxSum, int k) {
        int count = 1, currentSum = 0;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                count++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }
        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int ans;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, mid, k)) {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};