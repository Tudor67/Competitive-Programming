class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        const int MAX_BIT = 29;
        
        vector<int> arr2CountParity(MAX_BIT + 1, 0);
        for(int num2: arr2){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((num2 >> bit) & 1){
                    arr2CountParity[bit] ^= 1;
                }
            }
        }
        
        vector<int> xorSumCountParity(MAX_BIT + 1, 0);
        for(int num1: arr1){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((num1 >> bit) & 1){
                    xorSumCountParity[bit] ^= arr2CountParity[bit];
                }
            }
        }
        
        int xorSum = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            if(xorSumCountParity[bit]){
                xorSum |= (1 << bit);
            }
        }
        
        return xorSum;
    }
};