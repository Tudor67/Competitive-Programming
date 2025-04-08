class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        const int N = nums.size();

        int numsOR = 0;
        for(int num: nums){
            numsOR |= num;
        }

        return (1 << (N - 1)) * numsOR;
    }
};