class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const int N = nums.size();
        const long long NUMS_SUM = accumulate(nums.begin(), nums.end(), (long long)0);
        const long long TARGET_REM = NUMS_SUM % p;

        if(TARGET_REM == 0){
            return 0;
        }

        unordered_map<long long, int> maxIndexOf;
        maxIndexOf[0] = -1;

        int minLen = N;
        long long prefRem = 0;
        for(int i = 0; i < N; ++i){
            prefRem += nums[i];
            prefRem %= p;
            
            long long x = (prefRem - TARGET_REM + p) % p;
            if(maxIndexOf.count(x)){
                minLen = min(minLen, i - maxIndexOf[x]);
            }

            maxIndexOf[prefRem] = i;
        }

        if(minLen == N){
            minLen = -1;
        }

        return minLen;
    }
};