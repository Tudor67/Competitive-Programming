class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        const int N = usageLimits.size();

        vector<int> freq(N + 1);
        for(int usageLimit: usageLimits){
            freq[min(N, usageLimit)] += 1;
        }

        long long res = 0;
        long long prefSum = 0;
        for(int usageLimit = 1; usageLimit <= N; ++usageLimit){
            while(freq[usageLimit] >= 1){
                prefSum += usageLimit;
                if(prefSum >= (res + 1) * (res + 2) / 2){
                    res += 1;
                }
                freq[usageLimit] -= 1;
            }
        }
        
        return res;
    }
};