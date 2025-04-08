class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        int res = 0;
        for(int bit = 0; (1 << bit) <= MAX_NUM; ++bit){
            int oneBits = 0;
            for(int num: nums){
                oneBits += ((num >> bit) & 1);
            }
            if(oneBits >= 1){
                res += (1 << (oneBits - 1)) * (1 << (N - oneBits)) * (1 << bit);
            }
        }

        return res;
    }
};