class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> cnt;
        for(int num: nums){
            cnt[num] += 1;
        }
        
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
                cnt[nums[i]] -= 1;
                cnt[nums[j]] -= 1;
                int complement = -(nums[i] + nums[j]);
                if(nums[j] <= complement && cnt.count(complement) && cnt[complement] > 0){
                    answer.push_back({nums[i], nums[j], complement});
                }
                cnt[nums[i]] += 1;
                cnt[nums[j]] += 1;
            }
        }
        
        return answer;
    }
};