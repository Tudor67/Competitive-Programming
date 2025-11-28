class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int minOps = 0;
        for(int num: nums){
            int rem = num % 3;
            minOps += min(rem, 3 - rem);
        }
        return minOps;
    }
};