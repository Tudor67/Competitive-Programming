class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();
        
        // Step 1: find the xor of duplicate and missing number
        //         duplicateAndMissingXOR = nums[0] ^ nums[1] ^ ... ^ nums[N - 1] ^
        //                                  1 ^ 2 ^ ... ^ N
        int currentNumsXOR = 0;
        for(int num: nums){
            currentNumsXOR ^= num;
        }
        
        int targetNumsXOR = 0;
        for(int num = 1; num <= N; ++num){
            targetNumsXOR ^= num;
        }
        
        int duplicateAndMissingXOR = currentNumsXOR ^ targetNumsXOR;
        
        // Step 2: find the nonZeroLeastSignificantBit of duplicateAndMissingXOR
        //         let's call it splitBit (only one number (duplicate or missing) will contain that nonZero bit)
        //         remember that (duplicate != missing) => (duplicate ^ missing) contains at least one nonZero bit
        int splitBit = duplicateAndMissingXOR - (duplicateAndMissingXOR & (duplicateAndMissingXOR - 1));
        
        // Step 3: split the numbers [1 .. N] and [nums[0], nums[1], ..., nums[N - 1]] into two groups
        //         group1: numbers with splitBit set to one
        //         group2: the remaining numbers
        //         compute xor1 - the xor of group1
        //         compute xor2 - the xor of group2
        int xor1 = 0;
        int xor2 = 0;
        for(int num = 1; num <= N; ++num){
            if(num & splitBit){
                xor1 ^= num;
            }else{
                xor2 ^= num;
            }
            
            int i = num - 1;
            if(nums[i] & splitBit){
                xor1 ^= nums[i];
            }else{
                xor2 ^= nums[i];
            }
        }
        
        // Step 4: if xor1 is in nums => xor1 is the duplicate number
        //         otherwise => xor2 is the duplicate number
        //
        //         the missing number is just the xor of duplicate and duplicateAndMissingXOR
        int duplicate = xor1;
        if(find(nums.begin(), nums.end(), xor1) == nums.end()){
            duplicate = xor2;
        }
        int missing = duplicate ^ duplicateAndMissingXOR;
        
        return {duplicate, missing};
    }
};