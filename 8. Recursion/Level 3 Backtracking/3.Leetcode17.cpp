class Solution {
public:
    void backtrack(string& digits, vector<string>& result, string& current, int index, vector<string>& mapping) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, result, current, index + 1, mapping);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" // giving two empty strings in the start ensures that abc is maaped at index 2, def at index 3 and so on.
        };
        vector<string> result;
        string current;
        backtrack(digits, result, current, 0, mapping);
        return result;
    }
};