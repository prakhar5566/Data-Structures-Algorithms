class Solution {
public:
    void combination2(vector<int>& candidates, int target, int idx, vector<int>& ans, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(ans);
            return;
        }
        if (idx == candidates.size() || target < 0)
            return;

        ans.push_back(candidates[idx]);
        combination2(candidates, target-candidates[idx], idx+1, ans, result);
        ans.pop_back();
        
        int i = idx + 1;
        while (i < candidates.size() && candidates[i] == candidates[idx])
            i++;
        combination2(candidates, target, i, ans, result);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> ans;
        
        combination2(candidates, target, 0, ans, result);
        return result;
    }
};