class Solution {
private:
    long long computeTotalHeight(vector<int>& workerTimes, long long threshold){
        long long totalHeight = 0;
        for(long long workerTime: workerTimes){
            totalHeight += (-1 + sqrt(1 + 8 * threshold / workerTime)) / 2;
        }
        return totalHeight;
    }

public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0;
        long long r = 1e16;
        while(l != r){
            long long mid = (l + r) / 2;
            if(computeTotalHeight(workerTimes, mid) < mountainHeight){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
};