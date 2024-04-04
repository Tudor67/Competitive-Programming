class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_BIT = 30;
        
        int res = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int count = 0;
            for(int num: nums){
                if((num >> bit) & 1){
                    count += 1;
                }
            }
            if(count >= k){
                res |= (1 << bit);
            }
        }
        
        return res;
    }
};