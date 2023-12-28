class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;

        // Step 1: special case when nums contains only zeros
        if(count(nums.begin(), nums.end(), 0) == N){
            return 0;
        }

        // Step 2: standard counting approach
        int l = 0;
        while(l < N && nums[l] == 0){
            l += 1;
        }

        int r = N - 1;
        while(l < r && nums[r] == 0){
            r -= 1;
        }

        long long res = 1;
        long long consecZeros = 0;
        for(int i = l; i <= r; ++i){
            if(nums[i] == 0){
                consecZeros += 1;
            }
            if(nums[i] == 1){
                res = (res * (consecZeros + 1)) % MODULO;
                consecZeros = 0;
            }
        }

        return res;
    }
};