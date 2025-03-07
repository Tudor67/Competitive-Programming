class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        const int N = nums.size();

        for(int len = 2; len / 2 < N; len *= 2){
            for(int i = 0; i + len / 2 < N; i += len){
                int j = i + len / 2;
                int k = min(i + len, N);
                
                int firstIndex = lower_bound(nums.begin() + i, nums.begin() + j, pivot) - nums.begin();
                int secondIndex = upper_bound(nums.begin() + j, nums.begin() + k, pivot) - nums.begin();

                rotate(nums.begin() + firstIndex, nums.begin() + j, nums.begin() + secondIndex);
            }
        }

        return nums;
    }
};