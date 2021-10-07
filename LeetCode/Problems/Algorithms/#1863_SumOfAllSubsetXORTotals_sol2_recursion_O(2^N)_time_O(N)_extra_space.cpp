class Solution {
private:
    void rec(int level, int maskXOR, vector<int>& nums, int& sum){
        if(level == (int)nums.size()){
            sum += maskXOR;
        }else{
            rec(level + 1, maskXOR, nums, sum);
            rec(level + 1, maskXOR ^ nums[level], nums, sum);
        }
    }
    
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        rec(0, 0, nums, sum);
        return sum;
    }
};