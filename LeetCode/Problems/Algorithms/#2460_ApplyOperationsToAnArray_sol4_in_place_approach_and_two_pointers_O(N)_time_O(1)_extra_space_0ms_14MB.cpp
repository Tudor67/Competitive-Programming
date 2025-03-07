class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int N = nums.size();

        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] >= 1 && nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int size = 0;
        for(int i = 0; i < N; ++i){
            if(nums[i] >= 1){
                if(size == i){
                    size += 1;
                }else{
                    nums[size] = nums[i];
                    nums[i] = 0;
                    size += 1;
                }
            }
        }

        return nums;
    }
};