class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxSum = 0;
        int newNums = 0;
        for(int num: nums){
            while(maxSum + 1 < num && maxSum < n){
                newNums += 1;
                maxSum += (maxSum + 1);
            }
            maxSum += num;
        }
        while(maxSum < n){
            newNums += 1;
            maxSum += (maxSum + 1);
        }
        return newNums;
    }
};