class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const int N = nums.size();
        const int TARGET_REM = accumulate(nums.begin(), nums.end(), 0LL) % p;
        
        int minLen = 0;
        if(TARGET_REM >= 1){
            minLen = N;
            unordered_map<int, int> prefRemIdx;
            prefRemIdx[0] = -1;
            int prefRem = 0;
            for(int i = 0; i < N; ++i){
                prefRem += nums[i];
                prefRem %= p;

                int prefRemComplement = (p + prefRem - TARGET_REM) % p;
                if(prefRemIdx.count(prefRemComplement)){
                    minLen = min(i - prefRemIdx[prefRemComplement], minLen);
                }

                prefRemIdx[prefRem] = i;
            }

            if(minLen == N){
                minLen = -1;
            }
        }
        
        return minLen;
    }
};