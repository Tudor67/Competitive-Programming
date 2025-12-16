class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;

        // dp[i]: number of valid partitions for nums[i .. N - 1]
        vector<int> dp(N + 1);
        dp[N] = 1;

        deque<int> minDQ;
        deque<int> maxDQ;

        int wSum = dp[N]; // sum for dp[i + 1 .. j + 1]
        for(int i = N - 1, j = N - 1; i >= 0; --i){
            while(!minDQ.empty() && nums[i] < nums[minDQ.back()]){
                minDQ.pop_back();
            }
            minDQ.push_back(i);

            while(!maxDQ.empty() && nums[i] > nums[maxDQ.back()]){
                maxDQ.pop_back();
            }
            maxDQ.push_back(i);

            while(nums[maxDQ.front()] - nums[minDQ.front()] > k){
                if(minDQ.front() == j){
                    minDQ.pop_front();
                }
                if(maxDQ.front() == j){
                    maxDQ.pop_front();
                }
                wSum = (wSum - dp[j + 1] + MODULO) % MODULO;
                j -= 1;
            }

            dp[i] = wSum;
            wSum = (wSum + dp[i]) % MODULO;
        }

        return dp[0];
    }
};