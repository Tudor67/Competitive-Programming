class Solution {
public:
    bool validPartition(vector<int>& nums) {
        const int N = nums.size();

        vector<bool> isValid(N + 1, false);
        isValid[N] = true;
        for(int i = N - 2; i >= 0; --i){
            if(nums[i] == nums[i + 1] && isValid[i + 2]){
                isValid[i] = true;
            }
            if(i + 2 < N && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2] && isValid[i + 3]){
                isValid[i] = true;
            }
            if(i + 2 < N && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2] && isValid[i + 3]){
                isValid[i] = true;
            }
        }

        return isValid[0];
    }
};