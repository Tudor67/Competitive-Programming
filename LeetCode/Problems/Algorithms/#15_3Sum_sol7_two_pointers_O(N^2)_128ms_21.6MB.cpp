class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> answer;
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i - 1] == nums[i]){
                continue;
            }
            for(int j = i + 1, k = (int)nums.size() - 1; j < k;){
                if(nums[j] + nums[k] < -nums[i]){
                    j += 1;
                }else if(nums[j] + nums[k] > -nums[i]){
                    k -= 1;
                }else if(nums[j] + nums[k] == -nums[i]){
                    if(answer.empty() || answer.back() != vector<int>{nums[i], nums[j], nums[k]}){
                        answer.push_back({nums[i], nums[j], nums[k]});
                    }
                    j += 1;
                    k -= 1;
                }
            }
        }
        
        return answer;
    }
};