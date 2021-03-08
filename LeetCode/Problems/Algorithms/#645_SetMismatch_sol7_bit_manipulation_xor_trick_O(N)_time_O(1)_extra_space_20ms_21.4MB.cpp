class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();
        
        // originalNumsXOR = 1 ^ 2 ^ 3 ^ ... ^ N
        int originalNumsXOR = 0;
        for(int i = 1; i <= N; ++i){
            originalNumsXOR ^= i;
        }
        
        // currentNumsXOR = nums[0] ^ nums[1] ^ ... ^ nums[N - 1]
        int currentNumsXOR = 0;
        for(int num: nums){
            currentNumsXOR ^= num;
        }
        
        // duplicateMissingXOR = duplicate ^ missing
        int duplicateMissingXOR = originalNumsXOR ^ currentNumsXOR;
        // splitMask = 000..00100..000, contains the least significant 1-bit of (duplicate ^ missing)
        int splitMask = duplicateMissingXOR - (duplicateMissingXOR & (duplicateMissingXOR - 1));
        
        // originalXOR = i ^ j ^ k ^ .... ^ z,
        //               where each element 1 <= elem <= N and (elem & splitMask) != 0
        int originalXOR = 0;
        for(int i = 1; i <= N; ++i){
            if(i & splitMask){
                originalXOR ^= i;
            }
        }
        
        // currentXOR = nums[i1] ^ nums[i2] ^ ... ^ nums[ik],
        //              where each element 1 <= nums[idx] <= N and (nums[idx] & splitMask) != 0
        int currentXOR = 0;
        for(int num: nums){
            if(num & splitMask){
                currentXOR ^= num;
            }
        }
        
        // candidate is `duplicate` or `missing` number
        int candidate = originalXOR ^ currentXOR;
        int duplicate = 0;
        int missing = 0;
        for(int num: nums){
            if(candidate == num || (candidate ^ duplicateMissingXOR) == num){
                duplicate = num;
                missing = duplicate ^ duplicateMissingXOR;
            }
        }
        
        return {duplicate, missing};
    }
};