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
        
        int l = 0;
        long long sum = 0;
        for(int r = 0; r < 2 * N; ++r){
            sum += nums[r % N];
            while(sum > remTarget){
                sum -= nums[l % N];
                l += 1;
            }
            if(sum == remTarget){
                minLen = min(minLen, r - l + 1);
            }
        }
        
        int res = -1;
        if(minLen != INF){
            res = (target / TOTAL_SUM) * N + minLen;
        }
        
        return res;
    }
};