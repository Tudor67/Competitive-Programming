class Solution {
private:
    int getArrXOR(vector<int>& arr){
        int arrXOR = 0;
        for(int num: arr){
            arrXOR ^= num;
        }
        return arrXOR;
    }
    
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        return getArrXOR(arr1) & getArrXOR(arr2);
    }
};