class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;

        // dp[i]: number of valid partitions for nums[i .. N - 1]
        vector<int> dp(N + 1);
        dp[N] = 1;

        vector<int> dpSuffSum(N + 2);
        dpSuffSum[N + 1] = 0;
        dpSuffSum[N] = 1;

        deque<int> minDQ;
        deque<int> maxDQ;

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
                if(minDQ.front() < maxDQ.front()){
                    j = maxDQ.front() - 1;
                    maxDQ.pop_front();
                }else{
                    j = minDQ.front() - 1;
                    minDQ.pop_front();
                }
            }

            dp[i] = (dpSuffSum[i + 1] - dpSuffSum[j + 2] + MODULO) % MODULO;
            dpSuffSum[i] = (dp[i] + dpSuffSum[i + 1]) % MODULO;
        }

        return dp[0];
    }
};