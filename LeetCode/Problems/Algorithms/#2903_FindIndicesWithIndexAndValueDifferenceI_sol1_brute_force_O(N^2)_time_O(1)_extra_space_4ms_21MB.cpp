class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        const int N = nums.size();

        for(int i = 0; i < N; ++i){
            for(int j = i + indexDifference; j < N; ++j){
                if(abs(nums[i] - nums[j]) >= valueDifference){
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};