class Solution {
private:
    bool isPossible(vector<int>& batteries, int N, long long targetMinutes){
        const int B = batteries.size();

        long long extraMinutes = 0;
        for(int i = N; i < B; ++i){
            extraMinutes += min(targetMinutes, (long long)batteries[i]);
        }
        
        for(int i = 0; i < N && extraMinutes >= 0; ++i){
            if(batteries[i] < targetMinutes){
                extraMinutes -= (targetMinutes - batteries[i]);
            }
        }

        return (extraMinutes >= 0);
    }

public:
    long long maxRunTime(int N, vector<int>& batteries) {
        const int B = batteries.size();
        const long long TOTAL_MINUTES = accumulate(batteries.begin(), batteries.end(), (long long)0);

        long long l = 0;
        long long r = TOTAL_MINUTES / N;
        while(l != r){
            long long mid = (l + r + 1) / 2;
            if(isPossible(batteries, N, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};