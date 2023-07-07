class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_BIT = 31;
        
        vector<int> count(MAX_BIT + 1);
        for(int num: nums){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((num >> bit) & 1){
                    count[bit] += 1;
                }
            }
        }

        int res = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            if(count[bit] % 3 == 1){
                res |= (1 << bit);
            }
        }

        return res;
    }
};