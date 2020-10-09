class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int answer = 0;
        for(int i = 0, j = 1; i < nums.size(); ++i){
            j = max(i + 1, j);
            if(i > 0 && nums[i - 1] == nums[i]){
                // avoid duplicates
                continue;
            }
            while(j < nums.size() && nums[j] - nums[i] < k){
                j += 1;
            }
            if(j < nums.size() && i != j && nums[j] - nums[i] == k){
                answer += 1;
            }
        }
        
        return answer;
    }
};