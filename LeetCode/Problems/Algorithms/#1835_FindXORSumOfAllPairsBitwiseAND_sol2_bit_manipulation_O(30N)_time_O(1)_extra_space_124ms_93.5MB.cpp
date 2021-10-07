class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        const int MAX_BIT = 29;
        
        int arr2ParityMask = 0;
        for(int num2: arr2){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((num2 >> bit) & 1){
                    arr2ParityMask ^= (1 << bit);
                }
            }
        }
        
        int xorSum = 0;
        for(int num1: arr1){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((num1 >> bit) & 1){
                    xorSum ^= (((arr2ParityMask >> bit) & 1) << bit);
                }
            }
        }
        
        return xorSum;
    }
};