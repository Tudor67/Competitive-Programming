class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int N = nums.size();
        
        int answer = 0;
        bitset<10001> vis;
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