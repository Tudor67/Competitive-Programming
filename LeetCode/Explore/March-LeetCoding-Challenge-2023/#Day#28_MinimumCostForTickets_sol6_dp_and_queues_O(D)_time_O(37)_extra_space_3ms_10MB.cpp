class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int D = days.size();

        queue<pair<int, int>> last7;
        queue<pair<int, int>> last30;

        int minCost = 0;
        int last7Cost = 0;
        int last30Cost = 0;
        
        for(int i = 0; i < D; ++i){
            while(!last7.empty() && last7.front().first <= days[i] - 7){
                last7Cost = last7.front().second;
                last7.pop();
            }

            while(!last30.empty() && last30.front().first <= days[i] - 30){
                last30Cost = last30.front().second;
                last30.pop();
            }

            minCost = min({minCost + costs[0], last7Cost + costs[1], last30Cost + costs[2]});

            last7.push({days[i], minCost});
            last30.push({days[i], minCost});
        }

        return minCost;
    }
};