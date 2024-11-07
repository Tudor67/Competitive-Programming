class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        const int N = nums.size();

        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(nums[i] > nums[j] &&
                   popcount((unsigned int)nums[i]) != popcount((unsigned int)nums[j])){
                    return false;
                }
            }
        }

        return true;
    }
};