class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();
        
        int expectedXOR = 0;
        for(int num = 0; num <= N; ++num){
            expectedXOR ^= num;
        }
        
        int currentXOR = 0;
        for(int num: nums){
            currentXOR ^= num;
        }
        
        int missingNumber = expectedXOR ^ currentXOR;
        
        return missingNumber;
    }
};