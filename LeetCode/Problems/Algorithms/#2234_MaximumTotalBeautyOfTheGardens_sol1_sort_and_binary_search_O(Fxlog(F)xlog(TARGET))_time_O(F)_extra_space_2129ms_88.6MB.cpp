class Solution {
private:
    long long computeBeauty(long long completeGardens, long long full,
                            long long minFlowersOfPartialGardens, long long partial){
        return completeGardens * full + minFlowersOfPartialGardens * partial;
    }
    
    long long countTheNeedForPartialPlanting(vector<int>& sortedTruncatedFlowers, vector<long long>& prefSum,
                                             int lastPos, const long long& PARTIAL_TARGET){
        long long pos = upper_bound(sortedTruncatedFlowers.begin(), sortedTruncatedFlowers.begin() + lastPos + 1, PARTIAL_TARGET)
                        - sortedTruncatedFlowers.begin() - 1;
        // sortedTruncatedFlowers[0 .. pos] <= PARTIAL_TARGET
        // sortedTruncatedFlowers[pos + 1 .. lastPos] > PARTIAL_TARGET
        long long need = PARTIAL_TARGET * (pos + 1) - prefSum[pos];
        return need;
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
        
        // compute prefix sum vector for sortedTruncatedFlowers
        vector<long long> prefSum(F);
        prefSum[0] = sortedTruncatedFlowers[0];
        for(int i = 1; i < F; ++i){
            prefSum[i] = prefSum[i - 1] + sortedTruncatedFlowers[i];
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
                    long long l = sortedTruncatedFlowers[0];
                    long long r = target - 1;
                    while(l != r){
                        long long mid = (l + r + 1) / 2;
                        if(countTheNeedForPartialPlanting(sortedTruncatedFlowers, prefSum, i, mid) <= remainingFlowers){
                            l = mid;
                        }else{
                            r = mid - 1;
                        }
                    }
                    minFlowersOfPartialGardens = r;
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