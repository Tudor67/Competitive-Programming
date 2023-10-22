class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int N = nums.size();

        // dp[i]: max valid sum of a subsequence from nums[0 .. i] ending with nums[i]
        vector<int> dp(N);
        priority_queue<pair<int, int>> maxHeap;

        for(int i = 0; i < N; ++i){
            while(!maxHeap.empty() && i - maxHeap.top().second > k){
                maxHeap.pop();
            }

            if(maxHeap.empty()){
                dp[i] = nums[i];
            }else{
                dp[i] = nums[i] + max(0, maxHeap.top().first);
            }
            
            maxHeap.push({dp[i], i});
        }

        return *max_element(dp.begin(), dp.end());
    }
};