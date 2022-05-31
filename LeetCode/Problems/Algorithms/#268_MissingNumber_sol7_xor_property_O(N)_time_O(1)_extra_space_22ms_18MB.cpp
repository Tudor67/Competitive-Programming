class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();
        
        int numsXOR = 0;
        for(int num: nums){
            numsXOR ^= num;
        }
        
        int targetXOR = 0;
        for(int i = 1; i <= N; ++i){
            targetXOR ^= i;
        }
        
        return numsXOR ^ targetXOR;
    }
};