class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int N = (int)nums.size() - 1;
        
        int duplicate = -1;
        for(int num: nums){
            int idx = abs(num) - 1;
            if(nums[idx] < 0){
                duplicate = abs(num);
            }
            nums[idx] = -abs(nums[idx]);
        }
        
        for(int& num: nums){
            num = abs(num);
        }
        
        return duplicate;
    }
};