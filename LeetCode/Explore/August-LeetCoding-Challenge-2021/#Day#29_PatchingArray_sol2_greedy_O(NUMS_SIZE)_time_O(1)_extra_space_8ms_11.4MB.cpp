class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxSum = 0;
        int newNums = 0;
        int idx = 0;
        while(maxSum < n){
            if(idx < (int)nums.size() && maxSum + 1 >= nums[idx]){
                maxSum += nums[idx];
                idx += 1;
            }else{
                newNums += 1;
                maxSum += (maxSum + 1);
            }
        }
        return newNums;
    }
};