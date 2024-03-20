class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        const int N = nums.size();
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), (long long)0);
        const int INF = 1e9;

        // Case 1: target % TOTAL_SUM == 0
        if(target % TOTAL_SUM == 0){
            return (target / TOTAL_SUM) * N;
        }
        
        // Case 2: target % TOTAL_SUM != 0
        int minLen = INF;
        int remTarget = target % TOTAL_SUM;
        
        long long prefSum = 0;
        unordered_map<long long, int> maxIndexOf;
        
        for(int i = 0; i < 2 * N; ++i){
            prefSum += nums[i % N];
            if(maxIndexOf.count(prefSum - remTarget)){
                minLen = min(minLen, i - maxIndexOf[prefSum - remTarget]);
            }
            maxIndexOf[prefSum] = i;
        }
        
        int res = -1;
        if(minLen != INF){
            res = (target / TOTAL_SUM) * N + minLen;
        }
        
        return res;
    }
};