class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini = 1, maxi = 0;
        for (int e: piles)
            maxi = max (maxi, e);

        int ans = maxi;
        while (mini <= maxi) {
            int mid = mini + (maxi-mini)/2;

            long long time = 0;
            for (int p: piles)
                time += (p + mid - 1) / mid;

            if (time <= h) {
                ans = mid;
                maxi = mid-1;
            }
            else
                mini = mid+1;
        }

        return ans;
    }
};