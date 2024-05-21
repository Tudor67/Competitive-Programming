class Solution {
private:
    void rec(int i, int xorSum, int& totalXORSum, vector<int>& nums){
        if(i == (int)nums.size()){
            totalXORSum += xorSum;
        }else{
            rec(i + 1, xorSum, totalXORSum, nums);
            rec(i + 1, xorSum ^ nums[i], totalXORSum, nums);
        }
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int totalXORSum = 0;
        rec(0, 0, totalXORSum, nums);
        return totalXORSum;
    }
};