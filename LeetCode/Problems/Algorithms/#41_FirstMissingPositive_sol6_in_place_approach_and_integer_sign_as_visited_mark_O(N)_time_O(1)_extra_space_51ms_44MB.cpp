class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int N = nums.size();

        for(int i = 0; i < N; ++i){
            if(nums[i] <= 0 || N + 1 <= nums[i]){
                nums[i] = N + 1;
            }
        }

        for(int i = 0; i < N; ++i){
            int index = abs(nums[i]) - 1;
            if(index < N){
                nums[index] = -abs(nums[index]);
            }
        }

        for(int i = 0; i < N; ++i){
            if(nums[i] > 0){
                return i + 1;
            }
        }

        return N + 1;
    }
};