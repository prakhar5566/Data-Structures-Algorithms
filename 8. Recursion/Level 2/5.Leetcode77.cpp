class Solution {
public:

    vector<vector<int>> ans;

    void helper(int n, int k, int i, vector<int>& curr) {
        if (k == 0) {
            ans.push_back(curr);
            return ;
        }

        if (i > n)
            return ;

        curr.push_back(i);
        helper(n, k-1, i+1, curr);
        curr.pop_back();
        helper(n, k, i+1, curr);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        helper(n, k, 1, curr);

        return ans;
    }
};