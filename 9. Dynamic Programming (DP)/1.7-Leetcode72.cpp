class Solution {
public:
    int dp(string& word1, string& word2, int i, int j, vector<vector<int>>& memory) {
        if(i>=word1.size())
            return word2.size()-j;
        if(j>=word2.size())
            return word1.size()-i;

        if(memory[i][j] != -1)
            return memory[i][j];

        if(word1[i]==word2[j])
            memory[i][j] = dp(word1, word2, i+1, j+1, memory);
        else {
            int replace = 1 + dp(word1, word2, i+1, j+1, memory);
            int del = 1 + dp(word1, word2, i+1, j, memory);
            int insert = 1 + dp(word1, word2, i, j+1, memory);

            memory[i][j] = min( {replace, del, insert} );
        }
        return memory[i][j];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> mem(word1.size(), vector<int>(word2.size(), -1));
        return dp(word1, word2, 0, 0, mem);
    }
};