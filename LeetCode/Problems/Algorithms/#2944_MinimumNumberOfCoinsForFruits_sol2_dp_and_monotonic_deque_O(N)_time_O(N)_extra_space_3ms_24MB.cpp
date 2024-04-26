class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        const int N = prices.size();
        const int INF = 1e9;

        // dp[i]: min cost to take fruits[i .. N - 1]
        vector<int> dp(N + 1, INF);
        deque<int> monoDQ;

        dp[N] = 0;
        monoDQ.push_front(N);

        for(int i = N - 1; i >= 0; --i){
            int maxDist = i + 2;
            while(monoDQ.back() - i > maxDist){
                monoDQ.pop_back();
            }

            dp[i] = prices[i] + dp[monoDQ.back()];

            while(!monoDQ.empty() && dp[i] <= dp[monoDQ.front()]){
                monoDQ.pop_front();
            }
            monoDQ.push_front(i);
        }
        
        return dp[0];
    }
};