class Solution {
private:
    long long computeExtraNeed(vector<int>& stations, int radius, long long powerThreshold){
        const int N = stations.size();

        vector<long long> extra(N);
        long long wSum = accumulate(stations.begin(), stations.begin() + radius, (long long)0);

        for(int i = 0; i < N; ++i){
            if(i + radius < N){
                wSum += stations[i + radius];
            }
            if(i - radius - 1 >= 0){
                wSum -= stations[i - radius - 1];
                wSum -= extra[i - radius - 1];
            }
            if(wSum < powerThreshold){
                long long need = powerThreshold - wSum;
                extra[min(N - 1, i + radius)] += need;
                wSum += need;
            }
        }

        return accumulate(extra.begin(), extra.end(), (long long)0);
    }

public:
    long long maxPower(vector<int>& stations, int radius, int k) {
        const long long MIN_POWER = *min_element(stations.begin(), stations.end());
        const long long TOTAL_POWER = accumulate(stations.begin(), stations.end(), (long long)0);

        long long l = MIN_POWER;
        long long r = TOTAL_POWER + k;
        while(l != r){
            long long mid = (l + r + 1) / 2;
            if(computeExtraNeed(stations, radius, mid) > k){
                r = mid - 1;
            }else{
                l = mid;
            }
        }

        return r;
    }
};