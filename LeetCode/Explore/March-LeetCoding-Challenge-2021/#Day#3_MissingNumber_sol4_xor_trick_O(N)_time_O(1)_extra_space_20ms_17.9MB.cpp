class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();
        
        int rangeXOR = 0;
        for(int i = 1; i <= N; ++i){
            rangeXOR ^= i;
        }
        
        int numsXOR = 0;
        for(int num: nums){
            numsXOR ^= num;
        }
        
        int answer = rangeXOR ^ numsXOR;
        
        return answer;
    }
};