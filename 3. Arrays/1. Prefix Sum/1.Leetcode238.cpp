class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> anslp;
        int p=1;
        anslp.push_back(p);
        for(int i=1;i<nums.size();i++) {
            p*=nums[i-1];
            anslp.push_back(p);
        }
        p=1;
        for(int i=nums.size()-2;i>=0;i--) {
            p*=nums[i+1];
            anslp[i]*=p;
        }
        return anslp;
    }
};