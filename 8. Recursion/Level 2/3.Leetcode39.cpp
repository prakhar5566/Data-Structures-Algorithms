class Solution {
public:
    void combination(vector<int>& candidates, int target, int idx, vector<int>& ans, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(ans);
            return;
        }
        
        if (idx == candidates.size() || target < 0)
            return;

        combination(candidates, target, idx+1, ans, result);
        ans.push_back(candidates[idx]);
        combination(candidates, target-candidates[idx], idx, ans, result);
        ans.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        combination(candidates, target, 0, ans, result);
        return result;
    }
};