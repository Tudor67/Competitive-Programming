class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        const int MAX_BIT = 30;

        vector<vector<int>> freq2(2, vector<int>(MAX_BIT + 1));
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            for(int num2: nums2){
                int bitVal2 = (num2 >> bit) & 1;
                freq2[bitVal2][bit] += 1;
            }
        }

        int res = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            for(int num1: nums1){
                int bitVal1 = (num1 >> bit) & 1;
                int bitVal2 = 1 - bitVal1;
                if(freq2[bitVal2][bit] % 2 == 1){
                    res ^= (1 << bit);
                }
            }
        }

        return res;
    }
};