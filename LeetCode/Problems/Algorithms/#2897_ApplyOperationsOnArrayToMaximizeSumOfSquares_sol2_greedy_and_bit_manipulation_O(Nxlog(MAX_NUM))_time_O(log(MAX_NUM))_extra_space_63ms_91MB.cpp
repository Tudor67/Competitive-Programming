class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MAX_BIT = floor(log2(MAX_NUM));
        const int MODULO = 1'000'000'007;

        vector<int> count(MAX_BIT + 1);
        for(int num: nums){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((num >> bit) & 1){
                    count[bit] += 1;
                }
            }
        }

        long long res = 0;
        for(int i = 1; i <= k; ++i){
            long long num = 0;
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if(count[bit] >= 1){
                    count[bit] -= 1;
                    num |= (1 << bit);
                }
            }
            res += (num * num);
            res %= MODULO;
        }

        return res;
    }
};