class Solution {
private:
    static const int MAX_BIT = 29;
    
    vector<int> getArrBitParity(vector<int>& arr){
        vector<int> arrBitParity(MAX_BIT + 1, 0);
        for(int num: arr){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((num >> bit) & 1){
                    arrBitParity[bit] ^= 1;
                }
            }
        }
        return arrBitParity;
    }
    
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<int> arr1BitParity = getArrBitParity(arr1);
        vector<int> arr2BitParity = getArrBitParity(arr2);
        int xorSum = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            if(arr1BitParity[bit] == 1 && arr2BitParity[bit] == 1){
                xorSum |= (1 << bit);
            }
        }
        return xorSum;
    }
};