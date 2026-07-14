class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left=1;
        long long right=(long long)*min_element(time.begin(), time.end()) * totalTrips;

        while(left<right) {
            long long midTime= left + (right-left)/2;
            long long trips=0;

            for(int t: time)
                trips += midTime/t;

            if(trips>=totalTrips)
                right=midTime;
            else
                left=midTime+1;
        }

        return left;
    }
};