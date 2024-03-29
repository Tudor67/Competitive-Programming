class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        const int N = nums.size();

        int minIndexOfPrefMin = 0;
        int minIndexOfPrefMax = 0;
        for(int i = indexDifference; i < N; ++i){
            if(nums[minIndexOfPrefMin] > nums[i - indexDifference]){
                minIndexOfPrefMin = i - indexDifference;
            }
            if(nums[minIndexOfPrefMax] < nums[i - indexDifference]){
                minIndexOfPrefMax = i - indexDifference;
            }

            int j1 = minIndexOfPrefMin;
            if(nums[i] - nums[j1] >= valueDifference){
                return {i, j1};
            }
            int j2 = minIndexOfPrefMax;
            if(nums[j2] - nums[i] >= valueDifference){
                return {i, j2};
            }
        }

        return {-1, -1};
    }
};