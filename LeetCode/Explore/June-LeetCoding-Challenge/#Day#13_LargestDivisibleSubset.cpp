class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> answer;
        
        if(!nums.empty()){
            const int N = nums.size();
            
            sort(nums.begin(), nums.end());
            
            vector<int> dp(N, 1);
            vector<int> prev(N, -1);
            for(int i = 0; i < N; ++i){
                for(int j = i + 1; j < N; ++j){
                    if(nums[j] % nums[i] == 0 && dp[j] < 1 + dp[i]){
                        dp[j] = 1 + dp[i];
                        prev[j] = i;
                    }
                }
            }
            
            int pos = max_element(dp.begin(), dp.end()) - dp.begin();
            while(pos != -1){
                answer.push_back(nums[pos]);
                pos = prev[pos];
            }
            reverse(answer.begin(), answer.end());
        }
        
        return answer;
    }
};