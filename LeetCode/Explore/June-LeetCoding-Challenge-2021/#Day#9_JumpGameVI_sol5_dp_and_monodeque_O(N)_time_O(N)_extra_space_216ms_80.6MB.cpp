class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;
        vector<int> maxScore(N, -INF);
        maxScore[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for(int i = 1; i < N; ++i){
            while(i - dq.front() > k){
                dq.pop_front();
            }
            maxScore[i] = nums[i] + maxScore[dq.front()];
            while(!dq.empty() && maxScore[dq.back()] <= maxScore[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return maxScore[N - 1];
    }
};