class Solution {
private:
    long long computeBeauty(long long completeGardens, long long full,
                            long long minFlowersOfPartialGardens, long long partial){
        return completeGardens * full + minFlowersOfPartialGardens * partial;
    }
    
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        const long long F = flowers.size();
        
        // truncate flowers to max value target
        vector<int> sortedTruncatedFlowers(F);
        for(int i = 0; i < F; ++i){
            sortedTruncatedFlowers[i] = min(flowers[i], target);
        }
        
        // sort the truncated flowers in ascending order
        sort(sortedTruncatedFlowers.begin(), sortedTruncatedFlowers.end());
        
        // cost[i]: cost to make all flowers >= sortedTruncatedFlowers[i]
        vector<long long> cost(F);
        for(long long i = 1; i < F; ++i){
            if(sortedTruncatedFlowers[i - 1] == sortedTruncatedFlowers[i]){
                cost[i] = cost[i - 1];
            }else{
                cost[i] = cost[i - 1] + (sortedTruncatedFlowers[i] - sortedTruncatedFlowers[i - 1]) * i;
            }
        }
        
        // compute beauties of all valid plantings with newFlowers and return the max beauty
        // a valid planting consists of a complete planting for sortedTruncatedFlowers[i + 1 .. F - 1] and
        //                              a partial planting for sortedTruncatedFlowers[0 .. i]
        //                              using at most newFlowers
        long long maxBeauty = 0;
        long long suffSum = 0;
        for(long long i = F - 1; i >= 0; --i){
            // complete planting for sortedTruncatedFlowers[i + 1 .. F - 1]
            // partial planting for sortedTruncatedFlowers[0 .. i]
            long long needForCompletePlanting = target * (F - 1 - i) - suffSum;
            if(needForCompletePlanting <= newFlowers){
                long long remainingFlowers = newFlowers - needForCompletePlanting;
                long long minFlowersOfPartialGardens = 0;
                if(sortedTruncatedFlowers[0] < target){
                    int pos = upper_bound(cost.begin(), cost.begin() + i + 1, remainingFlowers) - cost.begin() - 1;
                    minFlowersOfPartialGardens = min(target - 1LL,
                                                     sortedTruncatedFlowers[pos] + (remainingFlowers - cost[pos]) / (pos + 1));
                }
                maxBeauty = max(maxBeauty, computeBeauty(F - 1 - i, full, minFlowersOfPartialGardens, partial));
            }
            suffSum += sortedTruncatedFlowers[i];
        }
        
        long long needForCompletePlanting = target * F - suffSum;
        if(needForCompletePlanting <= newFlowers){
            maxBeauty = max(maxBeauty, computeBeauty(F, full, 0, partial));
        }
        
        return maxBeauty;
    }
};