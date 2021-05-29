class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_ELEM = *max_element(nums.begin(), nums.end());
        
        int answer = 0;
        vector<bool> vis(MAX_ELEM + 1, false);
        for(int i = 0, j = 0, sum = 0; j < N; ++j){
            while(vis[nums[j]]){
                vis[nums[i]] = false;
                sum -= nums[i];
                i += 1;
            }
            vis[nums[j]] = true;
            sum += nums[j];
            answer = max(sum, answer);
        }
        
        return answer;
    }
};