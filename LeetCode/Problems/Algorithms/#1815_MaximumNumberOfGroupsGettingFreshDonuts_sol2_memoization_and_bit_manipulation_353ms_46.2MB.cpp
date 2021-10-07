class Solution {
private:    
    int solve(long long countMask, int r, const int& BATCH_SIZE, unordered_map<long long, int>& memo){
        if(countMask == 0){
            return 0;
        }
        long long state = (countMask << 5) | r;
        if(memo.count(state)){
            return memo[state];
        }
        int maxGroups = 0;
        for(int g = 1; g < BATCH_SIZE; ++g){
            int gCount = (countMask >> (5 * g - 5)) & 31;
            if(gCount > 0){
                long long nextCountMask = (((countMask >> (5 * g - 5)) - 1) << (5 * g - 5)) |
                                          (countMask & ((1LL << (5 * g - 5)) - 1));
                int nextR = ((r - g) + BATCH_SIZE) % BATCH_SIZE;
                int curMaxGroups = (nextR == 0) + solve(nextCountMask, nextR, BATCH_SIZE, memo);
                maxGroups = max(maxGroups, curMaxGroups);
            }
        }
        memo[state] = maxGroups;
        return maxGroups;
    }
    
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        const int G = groups.size();
        
        vector<int> count(batchSize, 0);
        for(int g: groups){
            count[g % batchSize] += 1;
        }
        
        int maxGroups = 0;
        if(batchSize == 1){
            maxGroups = G;
        }else if(batchSize == 2){
            maxGroups = count[0] + (count[1] + 1) / 2;
        }else{
            int minFirstLastCount = min(count[1], count[batchSize - 1]);
            int fixedGroups = count[0] + minFirstLastCount;
            count[batchSize - 1] -= minFirstLastCount;
            count[1] -= minFirstLastCount;
            count[0] = 0;
            
            long long countMask = 0;
            for(int g = 1; g < batchSize; ++g){
                countMask |= ((long long)count[g] << (5 * g - 5));
            }
            
            unordered_map<long long, int> memo;
            for(int r = 0; r < batchSize; ++r){
                int curMaxGroups = fixedGroups + solve(countMask, r, batchSize, memo);
                maxGroups = max(maxGroups, curMaxGroups);
            }
        }
        
        return maxGroups;
    }
};