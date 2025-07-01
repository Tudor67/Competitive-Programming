class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        const int N = nums.size();

        vector<int> validIndices;

        int indexOfLastIncluded = -1;
        for(int i = 0; i < N; ++i){
            if(nums[i] == key){
                for(int j = max(indexOfLastIncluded + 1, i - k); j <= min(N - 1, i + k); ++j){
                    validIndices.push_back(j);
                }
                indexOfLastIncluded = i + k;
            }
        }

        return validIndices;
    }
};