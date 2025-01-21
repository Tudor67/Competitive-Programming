class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        const int MAX_BIT = 30;

        vector<int> freq2(MAX_BIT + 1);
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            for(int num2: nums2){
                if((num2 >> bit) & 1){
                    freq2[bit] += 1;
                }
            }
        }

        int res = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            for(int num1: nums1){
                if((num1 >> bit) & 1){
                    int zeroBits2 = N2 - freq2[bit];
                    if(zeroBits2 % 2 == 1){
                        res ^= (1 << bit);
                    }
                }else{
                    int oneBits2 = freq2[bit];
                    if(oneBits2 % 2 == 1){
                        res ^= (1 << bit);
                    }
                }
            }
        }

        return res;
    }
};