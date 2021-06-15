class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;
        vector<int> maxScore(N, -INF);
        maxScore[0] = nums[0];
        priority_queue<pair<int, int>> maxHeap;
        maxHeap.push({maxScore[0], 0});
        for(int i = 1; i < N; ++i){
            while(i - maxHeap.top().second > k){
                maxHeap.pop();
            }
            maxScore[i] = nums[i] + maxScore[maxHeap.top().second];
            while(!maxHeap.empty() && maxScore[maxHeap.top().second] <= maxScore[i]){
                maxHeap.pop();
            }
            maxHeap.push({maxScore[i], i});
        }
        return maxScore[N - 1];
    }
};