class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        const int N = nums.size();

        vector<int> minIndexOfPrefMin(N);
        vector<int> minIndexOfPrefMax(N);

        for(int i = 1; i < N; ++i){
            minIndexOfPrefMin[i] = minIndexOfPrefMin[i - 1];
            minIndexOfPrefMax[i] = minIndexOfPrefMax[i - 1];
            if(nums[minIndexOfPrefMin[i - 1]] > nums[i]){
                minIndexOfPrefMin[i] = i;
            }
            if(nums[minIndexOfPrefMax[i - 1]] < nums[i]){
                minIndexOfPrefMax[i] = i;
            }
        }

        for(int i = indexDifference; i < N; ++i){
            int j1 = minIndexOfPrefMin[i - indexDifference];
            if(nums[i] - nums[j1] >= valueDifference){
                return {i, j1};
            }
            int j2 = minIndexOfPrefMax[i - indexDifference];
            if(nums[j2] - nums[i] >= valueDifference){
                return {i, j2};
            }
        }

        return {-1, -1};
    }
};