class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const long long N = nums.size();
        const long long TARGET_S1 = N * (N + 1) / 2;               // TARGET_S1 = 1 + 2 + 3 + ... + n
        const long long TARGET_S2 = N * (N + 1) * (2 * N + 1) / 6; // TARGET_S2 = 1^2 + 2^2 + ... + n^2
        
        long long currentS1 = 0;
        long long currentS2 = 0;
        for(int num: nums){
            currentS1 += num;
            currentS2 += num * num;
        }
        
        long long duplicateMissingDiff = currentS1 - TARGET_S1;
        long long duplicateMissingSum = (currentS2 - TARGET_S2) / duplicateMissingDiff;
        
        int duplicate = (duplicateMissingDiff + duplicateMissingSum) / 2;
        int missing = duplicateMissingSum - duplicate;
        
        return {duplicate, missing};
    }
};