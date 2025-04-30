class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        const int N = nums.size();

        int validSubarrays = 0;
        for(int i = 1; i + 1 < N; ++i){
            if(2 * (nums[i - 1] + nums[i + 1]) == nums[i]){
                validSubarrays += 1;
            }
        }

        return validSubarrays;
    }
};