class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;
        
        // dp[i]: max sum of a valid subsequence ending at position i
        vector<int> dp(N);
        priority_queue<pair<int, int>> maxHeap;
        for(int i = 0; i < N; ++i){
            while(!maxHeap.empty() && i - maxHeap.top().second > k){
                maxHeap.pop();
            }
            if(maxHeap.empty()){
                dp[i] = nums[i];
            }else{
                dp[i] = nums[i] + maxHeap.top().first;
            }
            if(dp[i] > 0){
                maxHeap.emplace(dp[i], i);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};