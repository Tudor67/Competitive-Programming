class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int D = days.size();
        const int MIN_DAY = days.front();
        const int MAX_DAY = days.back();

        // dp[currentDay]: min cost to travel [currentDay .. MAX_DAY]
        //                 which are in the input vector days[i .. D - 1]
        vector<int> dp(MAX_DAY + 31);
        
        int i = D - 1;
        for(int currentDay = MAX_DAY; currentDay >= MIN_DAY; --currentDay){
            if(days[i] == currentDay){
                dp[currentDay] = min({costs[0] + dp[currentDay + 1],
                                      costs[1] + dp[currentDay + 7],
                                      costs[2] + dp[currentDay + 30]});
                i -= 1;
            }else{
                dp[currentDay] = dp[currentDay + 1];
            }
        }

        return dp[MIN_DAY];
    }
};