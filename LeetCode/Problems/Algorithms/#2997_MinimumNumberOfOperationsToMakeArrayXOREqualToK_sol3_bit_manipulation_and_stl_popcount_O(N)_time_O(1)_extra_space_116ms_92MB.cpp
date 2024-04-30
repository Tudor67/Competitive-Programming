class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int N = nums.size();

        int numsXOR = 0;
        for(int num: nums){
            numsXOR ^= num;
        }

        return popcount((unsigned int)(numsXOR ^ k));
    }
};