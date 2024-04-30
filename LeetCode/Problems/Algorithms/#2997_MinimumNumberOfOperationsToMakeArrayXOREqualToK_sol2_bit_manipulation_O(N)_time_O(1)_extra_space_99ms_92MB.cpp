class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int N = nums.size();

        int numsXOR = 0;
        for(int num: nums){
            numsXOR ^= num;
        }

        int minOps = 0;
        int diffMask = numsXOR ^ k;
        while(diffMask > 0){
            minOps += (diffMask & 1);
            diffMask >>= 1;
        }
        
        return minOps;
    }
};