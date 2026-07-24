class Solution {
public:
    void subarray(vector<int>& nums,vector<int>& ans , vector<vector<int>>& allsets,int index) {
        if (index == nums.size()) {
            allsets.push_back(ans);
            return;
        }

        ans.push_back(nums[index]);
        subarray(nums, ans, allsets, index+1);
        ans.pop_back();

        index++;
        while (index < nums.size() && nums[index] == nums[index-1])
            index++;
        subarray(nums, ans, allsets, index);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        vector<vector<int>> allsets;
        vector<int> ans;
        
        subarray(nums , ans , allsets ,0 );
        return allsets;
    }
};

// alternate way
class Solution {
public:
    void Subsets(vector<int> nums, vector<int> ans, vector<vector<int>>& result, int idx, bool prevIncluded) {
        if(idx==nums.size()) {
            result.push_back(ans);
            return;
        }

        Subsets(nums, ans, result, idx+1, false);
        if(idx==0 || nums[idx]!=nums[idx-1] || prevIncluded) {
            ans.push_back(nums[idx]);
            Subsets(nums, ans, result, idx+1, true);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        vector<int> ans;

        Subsets(nums, ans, result, 0, false);
        return result;
    }
};