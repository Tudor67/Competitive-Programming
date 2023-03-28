class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int D = days.size();
        const int MIN_DAY = days.front();
        const int MAX_DAY = days.back();

        // dp[currentDay % 31]: min cost to travel [currentDay .. MAX_DAY]
        //                      which are in the input vector days[i .. D - 1]
        vector<int> dp(31);
        
        int i = D - 1;
        for(int currentDay = MAX_DAY; currentDay >= MIN_DAY; --currentDay){
            if(days[i] == currentDay){
                dp[currentDay % 31] = min({costs[0] + dp[(currentDay + 1) % 31],
                                           costs[1] + dp[(currentDay + 7) % 31],
                                           costs[2] + dp[(currentDay + 30) % 31]});
                i -= 1;
            }else{
                dp[currentDay % 31] = dp[(currentDay + 1) % 31];
            }
        }

        return dp[MIN_DAY % 31];
    }
};