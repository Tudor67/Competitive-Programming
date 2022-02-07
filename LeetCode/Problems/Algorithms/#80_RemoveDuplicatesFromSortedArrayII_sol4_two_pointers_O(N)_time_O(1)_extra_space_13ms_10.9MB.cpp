class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        
        int i = 0;
        int count = 1;
        for(int j = 1; j < N; ++j){
            if(nums[i] == nums[j]){
                if(count == 1){
                    i += 1;
                    nums[i] = nums[j];
                    count += 1;
                }
            }else{
                i += 1;
                nums[i] = nums[j];
                count = 1;
            }
        }
        
        return i + 1;
    }
};