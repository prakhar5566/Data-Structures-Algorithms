class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCapacity=1, maxCapacity=0;
        for(int w: weights) {
            minCapacity=max(w, minCapacity);
            maxCapacity+=w;
        }

        while(minCapacity < maxCapacity) {
            int mid= minCapacity + (maxCapacity-minCapacity)/2;
            int count=1, currentLoad=0;

            for(int w: weights) {
                if(currentLoad+w > mid) {
                    count++;
                    currentLoad=0;
                }
                currentLoad += w;
            }

            if(count<=days)
                maxCapacity=mid;
            else
                minCapacity=mid+1;
        }
        return minCapacity;
    }
};