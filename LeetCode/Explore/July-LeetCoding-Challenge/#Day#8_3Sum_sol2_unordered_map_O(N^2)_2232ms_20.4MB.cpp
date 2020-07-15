class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& input_nums) {
        unordered_map<int, int> cnt;
        for(int num: input_nums){
            cnt[num] += 1;
        }
        
        // If a num appears more than 2 times in nums: keep only 2 copies
        // Exception for num = 0: keep max 3 copies, because we can create (0, 0, 0)
        vector<int> nums;
        for(const pair<int, int>& p: cnt){
            int max_freq = (p.first == 0 ? 3 : 2);
            for(int k = 1; k <= min(max_freq, p.second); ++k){
                nums.push_back(p.first);
            }
            cnt[p.first] = min(max_freq, p.second);
        }
        
        // Sort in non-decreasing order
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