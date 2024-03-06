class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        const int N = nums.size();

        int res = 0;
        for(int i = 0; i < N; ++i){
            if(__builtin_popcount(i) == k){
                res += nums[i];
            }
        }
        
        return res;
    }
};