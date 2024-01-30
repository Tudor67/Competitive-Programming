class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        const int N = usageLimits.size();
        
        vector<int> sortedUsageLimits = usageLimits;
        sort(sortedUsageLimits.begin(), sortedUsageLimits.end());

        long long res = 0;
        long long prefSum = 0;
        for(int usageLimit: sortedUsageLimits){
            prefSum += usageLimit;
            if(prefSum >= (res + 1) * (res + 2) / 2){
                res += 1;
            }
        }
        
        return res;
    }
};