class Solution {
public:
    vector<string> ans;
    void helper(string& str, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(str);
            return;
        }

        if (open > 0) {
            str.push_back('(');
            helper(str, open-1, close);
            str.pop_back();
        }
        if (close > open) {
            str.push_back(')');
            helper(str, open, close-1);
            str.pop_back();
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        string str = "";
        helper(str, n, n);
        return ans;
    }
};