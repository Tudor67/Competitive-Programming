class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int N = nums.size();

        for(int i = 0; i < N; ++i){
            while(0 < nums[i] && nums[i] <= N && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < N; ++i){
            if(i + 1 != nums[i]){
                return i + 1;
            }
        }

        return N + 1;
    }
};