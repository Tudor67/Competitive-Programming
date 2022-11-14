class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        
        int len = 1;
        for(int i = 1; i < N; ++i){
            if(nums[len - 1] != nums[i]){
                len += 1;
                nums[len - 1] = nums[i];
            }
        }
        
        return len;
    }
};