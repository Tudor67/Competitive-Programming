class Solution {
private:
    bool isPossible(int n, vector<int>& batteries, long long threshold){
        long long remTime = n * threshold;
        for(long long b: batteries){
            remTime -= min(b, threshold);
        }
        return (remTime <= 0);
    }

public:
    long long maxRunTime(int n, vector<int>& batteries) {
        const long long TOTAL_TIME = accumulate(batteries.begin(), batteries.end(), (long long)0);

        long long l = 0;
        long long r = TOTAL_TIME;
        while(l != r){
            long long mid = (l + r + 1) / 2;
            if(isPossible(n, batteries, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};