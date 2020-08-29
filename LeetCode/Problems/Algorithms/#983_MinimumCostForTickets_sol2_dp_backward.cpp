class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int N = days.size();
        const int MIN_DAY = days.front();
        const int MAX_DAY = days.back();
        
        vector<int> min_cost(MAX_DAY + 30 + 1, 0);
        for(int current_day = MAX_DAY, day_idx = N - 1; current_day >= MIN_DAY; --current_day){
            if(days[day_idx] < current_day){
                min_cost[current_day] = min_cost[current_day + 1];
            }else{
                min_cost[current_day] = min({min_cost[current_day + 1] + costs[0], 
                                             min_cost[current_day + 7] + costs[1],
                                             min_cost[current_day + 30] + costs[2]});
                day_idx -= 1;
            }
        }

        return min_cost[MIN_DAY];
    }
};