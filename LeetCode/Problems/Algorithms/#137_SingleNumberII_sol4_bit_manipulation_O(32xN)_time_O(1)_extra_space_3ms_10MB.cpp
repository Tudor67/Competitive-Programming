class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_BIT = 31;

        int res = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int count1 = 0;
            for(int num: nums){
                if((num >> bit) & 1){
                    count1 += 1;
                }
            }
            
            if(count1 % 3 == 1){
                res |= (1 << bit);
            }
        }

        return res;
    }
};