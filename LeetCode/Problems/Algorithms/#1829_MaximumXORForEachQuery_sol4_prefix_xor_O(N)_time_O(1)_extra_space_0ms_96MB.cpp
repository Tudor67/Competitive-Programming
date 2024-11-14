class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int N = nums.size();
        const int FULL_MASK = (1 << maximumBit) - 1;

        vector<int> res(N);
        int prefXOR = 0;
        for(int i = 0; i < N; ++i){
            prefXOR ^= nums[i];
            res[N - 1 - i] = prefXOR ^ FULL_MASK;
        }

        return res;
    }
};