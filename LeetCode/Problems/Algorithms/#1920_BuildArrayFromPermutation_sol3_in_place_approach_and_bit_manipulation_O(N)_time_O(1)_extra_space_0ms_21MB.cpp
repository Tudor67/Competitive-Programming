class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        const int N = nums.size();

        for(int i = 0; i < N; ++i){
            if(nums[i] < 0){
                continue;
            }
            int initVal = nums[i];
            int currIndex = i;
            while(nums[currIndex] != i){
                int nextIndex = nums[currIndex];
                nums[currIndex] = ~nums[nextIndex];
                currIndex = nextIndex;
            }
            nums[currIndex] = ~initVal;
        }

        for(int i = 0; i < N; ++i){
            nums[i] = ~nums[i];
        }

        return nums;
    }
};