class Solution {
private:
    void generateSubsets(int i, int subsetXOR, vector<int>& nums, int& res){
        if(i == (int)nums.size()){
            res += subsetXOR;
        }else{
            generateSubsets(i + 1, subsetXOR, nums, res);
            generateSubsets(i + 1, subsetXOR ^ nums[i], nums, res);
        }
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        generateSubsets(0, 0, nums, res);
        return res;
    }
};