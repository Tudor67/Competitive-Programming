class Solution {
private:
    long long computeTrips(vector<int>& times, const long long& MAX_TIME){
        long long trips = 0;
        for(int t: times){
            trips += (MAX_TIME / t);
        }
        return trips;
    }

public:
    long long minimumTime(vector<int>& times, int totalTrips) {
        const int N = times.size();
        const long long MIN_TIME = *min_element(times.begin(), times.end());

        long long l = MIN_TIME;
        long long r = MIN_TIME * totalTrips;
        while(l != r){
            long long mid = (l + r) / 2;
            if(computeTrips(times, mid) < totalTrips){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r;
    }
};