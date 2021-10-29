class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int N = nums.size();
        
        for(int i = 0; i < N - 1; ++i){
            for(int j = i + 1; j < N; ++j){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
        
        vector<vector<int>> triplets;
        for(int i = 0; i < N - 2; ++i){
            if(i > 0 && nums[i - 1] == nums[i]){
                continue;
            }
            int k = N - 1;
            for(int j = i + 1; j < k; ++j){
                if(j > i + 1 && nums[j - 1] == nums[j]){
                    continue;
                }
                int target = -(nums[i] + nums[j]);
                while(j < k && target < nums[k]){
                    --k;
                }
                if(j < k && nums[k] == target){
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    if(triplets.empty() || triplets.back() != triplet){
                        triplets.push_back(triplet);
                    }
                }
            }
        }
        
        return triplets;
    }
};