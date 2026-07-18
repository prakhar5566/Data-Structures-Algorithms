class Solution {
public:
    bool isPalindrome(string s) {
        string check;
        for(char c:s) {
            if(isalnum(c))
            check+=tolower(c);
        }
        int i=0,j=check.size();
        while(i<j/2) {
            if(check[i]!=check[j-i-1])
            return false;
            i++;
        }
        return true;
    }
};