class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_BIT = 13;
        
        vector<int> expectedCount(MAX_BIT + 1, 0);
        for(int num = 0; num <= N; ++num){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                expectedCount[bit] += ((num >> bit) & 1);
            }
        }
        
        vector<int> currentCount(MAX_BIT + 1, 0);
        for(int num: nums){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                currentCount[bit] += ((num >> bit) & 1);
            }
        }
        
        int missingNumber = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            if(currentCount[bit] < expectedCount[bit]){
                missingNumber |= (1 << bit);
            }
        }
        
        return missingNumber;
    }
};