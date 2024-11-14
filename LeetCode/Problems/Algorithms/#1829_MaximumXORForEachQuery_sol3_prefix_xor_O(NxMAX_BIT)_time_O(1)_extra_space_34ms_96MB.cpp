class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int N = nums.size();

        vector<int> res(N);
        int prefXOR = 0;
        for(int i = 0; i < N; ++i){
            prefXOR ^= nums[i];
            for(int bit = 0; bit < maximumBit; ++bit){
                if(((prefXOR >> bit) & 1) == 0){
                    res[N - 1 - i] |= (1 << bit);
                }
            }
        }

        return res;
    }
};