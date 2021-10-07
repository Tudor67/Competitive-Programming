class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        return accumulate(arr1.begin(), arr1.end(), 0, bit_xor<int>()) &
               accumulate(arr2.begin(), arr2.end(), 0, bit_xor<int>());
    }
};