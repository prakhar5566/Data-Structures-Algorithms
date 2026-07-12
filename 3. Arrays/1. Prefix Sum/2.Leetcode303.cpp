class NumArray {
public:
    vector<long long> prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum.push_back(nums[0]);
        for(int i=1;i<nums.size();i++) {
            prefixSum.push_back(prefixSum[i-1]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
            return (int)prefixSum[right];
        return (int)(prefixSum[right]-prefixSum[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */