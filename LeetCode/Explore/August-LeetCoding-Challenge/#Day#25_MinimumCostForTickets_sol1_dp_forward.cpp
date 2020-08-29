class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int N = days.size();
        const int INF = 1e9;
        const int MAX_DAY = days.back();
        
        vector<int> min_cost(MAX_DAY + 1, INF);
        min_cost[0] = 0;
        
        for(int current_day = 1, day_idx = 0; current_day <= MAX_DAY; ++current_day){
            if(current_day < days[day_idx]){
                min_cost[current_day] = min_cost[current_day - 1];
            }else{
                int cost1 = costs[0] + (current_day >= 1 ? min_cost[current_day - 1] : 0);
                int cost7 = costs[1] + (current_day >= 7 ? min_cost[current_day - 7] : 0);
                int cost30 = costs[2] + (current_day >= 30 ? min_cost[current_day - 30] : 0);
                min_cost[current_day] = min({cost1, cost7, cost30});
                day_idx += 1;
            }
        }

        return min_cost[MAX_DAY];
    }
};