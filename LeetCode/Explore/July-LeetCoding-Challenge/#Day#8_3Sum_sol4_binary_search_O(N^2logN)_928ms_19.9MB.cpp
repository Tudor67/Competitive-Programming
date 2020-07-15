class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> answer;
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i - 1] == nums[i]){
                // Ignore duplicate triplets with the same first element
                continue;
            }
            for(int j = i + 1; j < nums.size(); ++j){
                if(j > i + 1 && nums[j - 1] == nums[j]){
                    // Ignore duplicate triplets with the same first & second element
                    continue;
                }
                int complement = -(nums[i] + nums[j]);
                if(nums[j] <= complement){
                    vector<int>::iterator it = lower_bound(nums.begin() + j + 1, nums.end(), complement);
                    if(it != nums.end() && *it == complement){
                        answer.push_back({nums[i], nums[j], complement});
                    }
                }
            }
        }
        
        return answer;
    }
};