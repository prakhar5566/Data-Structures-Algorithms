class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);

        int s=0, e=nums.size()-1;
        while(s<=e) {
            int mid=s+(e-s)/2;
            if(nums[mid]==target) {
                ans[0]=mid;
                e=mid-1;
            }
            else if(nums[mid]>target)
            e=mid-1;
            else
            s=mid+1;
        }
        
        s=0;
        e=nums.size()-1;
        while(s<=e) {
            int mid=s+(e-s)/2;
            if(nums[mid]==target) {
                ans[1]=mid;
                s=mid+1;
            }
            else if(target<nums[mid])
            e=mid-1;
            else
            s=mid+1;
        }
        
        return ans;
    }
};