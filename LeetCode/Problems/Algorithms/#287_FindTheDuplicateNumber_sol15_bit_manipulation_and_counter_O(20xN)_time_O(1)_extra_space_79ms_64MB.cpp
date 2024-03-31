class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int N = nums.size() - 1;
        const int MAX_BIT = 20;

        int res = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int bitFreq = 0;
            for(int num: nums){
                bitFreq += ((num >> bit) & 1);
            }

            int bitTargetFreq = 0;
            for(int i = 1; i <= N; ++i){
                bitTargetFreq += ((i >> bit) & 1);
            }

            if(bitFreq > bitTargetFreq){
                res |= (1 << bit);
            }
        }

        return res;
    }
};