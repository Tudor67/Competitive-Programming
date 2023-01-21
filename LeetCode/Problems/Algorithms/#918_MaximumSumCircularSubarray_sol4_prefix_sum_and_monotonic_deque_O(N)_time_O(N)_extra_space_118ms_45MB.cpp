class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int N = nums.size();

        int res = nums[0];
        int prefSum = 0;
        deque<pair<int, int>> dq;
        dq.push_back({0, -1});

        for(int i = 0; i < 2 * N; ++i){
            prefSum += nums[i % N];

            while(i - dq.front().second > N){
                dq.pop_front();
            }
            
            res = max(res, prefSum - dq.front().first);

            while(!dq.empty() && dq.back().first >= prefSum){
                dq.pop_back();
            }
            dq.push_back({prefSum, i});
        }

        return res;
    }
};