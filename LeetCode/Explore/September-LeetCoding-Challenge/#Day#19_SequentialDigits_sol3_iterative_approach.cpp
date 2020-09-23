class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums(9);
        iota(nums.begin(), nums.end(), 1);
        
        int prevSize = 0;
        for(int len = 2; len <= 9; ++len){
            int currentSize = nums.size();
            for(int i = prevSize; i < currentSize; ++i){
                if(nums[i] % 10 + 1 <= 9){
                    nums.push_back(nums[i] * 10 + nums[i] % 10 + 1);
                }
            }
            prevSize = currentSize;
        }
        
        vector<int> answer;
        for(int num: nums){
            if(low <= num && num <= high){
                answer.push_back(num);
            }
        }
        
        return answer;
    }
};