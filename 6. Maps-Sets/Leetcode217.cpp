class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int x: nums) {
            freq[x]++;
            if  (freq[x] > 1)
                return true;
        }
        return false;
    }
};

// using sets
class Solution {
    public :
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int x: nums) {
            if(seen.count(x))
                return true;
            seen.insert(x);
        }
        return false;
    }
};