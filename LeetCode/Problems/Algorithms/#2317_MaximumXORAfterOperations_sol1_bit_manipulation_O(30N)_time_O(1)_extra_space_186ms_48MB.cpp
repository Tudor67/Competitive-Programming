class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        const int N = nums.size();
        
        int res = 0;
        for(int num: nums){
            for(int bit = 0; bit <= 30; ++bit){
                if((num >> bit) & 1){
                    res |= (1 << bit);
                }
            }
        }
        
        return res;
    }
};