class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int N = nums.size();
        
        for(int i = 0; i < N - 1; ++i){
            for(int j = i + 1; j < N; ++j){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
        
        int triplets = 0;
        for(int i = 0; i < N - 2; ++i){
            for(int j = i + 1; j < N - 1; ++j){
                int k = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin();
                triplets += (k - 1 - j);
            }
        }
        
        return triplets;
    }
};