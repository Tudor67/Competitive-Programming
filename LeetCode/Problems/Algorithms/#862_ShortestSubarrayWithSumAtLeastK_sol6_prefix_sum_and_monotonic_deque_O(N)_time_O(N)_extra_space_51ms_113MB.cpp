class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;

        int minLen = INF;
        deque<pair<long long, int>> dq;
        dq.push_back({0, -1});

        long long prefSum = 0;
        for(int i = 0; i < N; ++i){
            prefSum += nums[i];
            while(!dq.empty() && dq.back().first >= prefSum){
                dq.pop_back();
            }
            
            dq.push_back({prefSum, i});

            while(!dq.empty() && dq.front().first + k <= prefSum){
                minLen = min(minLen, i - dq.front().second);
                dq.pop_front();
            }
        }

        if(minLen == INF){
            minLen = -1;
        }

        return minLen;
    }
};