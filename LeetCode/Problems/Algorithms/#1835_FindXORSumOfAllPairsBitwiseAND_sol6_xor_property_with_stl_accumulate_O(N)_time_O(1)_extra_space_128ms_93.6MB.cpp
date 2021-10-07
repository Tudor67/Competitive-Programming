class Solution {
private:
    static int bitXOR(const int& LHS, const int& RHS){
        return (LHS ^ RHS);
    }
    
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        return accumulate(arr1.begin(), arr1.end(), 0, bitXOR) &
               accumulate(arr2.begin(), arr2.end(), 0, bitXOR);
    }
};