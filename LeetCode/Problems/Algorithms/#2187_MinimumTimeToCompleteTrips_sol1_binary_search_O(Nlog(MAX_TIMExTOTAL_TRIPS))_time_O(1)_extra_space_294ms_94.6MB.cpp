class Solution {
private:
    long long countCompletedTrips(vector<int>& times, const long long& TIME_LIMIT){
        long long completedTrips = 0;
        for(int t: times){
            completedTrips += (TIME_LIMIT / t);
        }
        return completedTrips;
    }
    
public:
    long long minimumTime(vector<int>& times, int totalTrips) {
        const int N = times.size();
        const long long MAX_TIME = *max_element(times.begin(), times.end());
        
        long long l = 1;
        long long r = MAX_TIME * (totalTrips + N - 1) / N;
        while(l != r){
            long long mid = (l + r) / 2;
            if(countCompletedTrips(times, mid) < totalTrips){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        return r;
    }
};