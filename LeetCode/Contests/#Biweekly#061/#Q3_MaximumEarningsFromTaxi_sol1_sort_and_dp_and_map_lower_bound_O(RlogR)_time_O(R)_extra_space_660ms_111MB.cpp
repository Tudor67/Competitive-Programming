class Solution {
private:
    static bool incEndPointComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    long long maxTaxiEarnings(int N, vector<vector<int>>& rides) {
        const int R = rides.size();
        
        sort(rides.begin(), rides.end(), incEndPointComp);
        
        // maxProfit[p]: max profit in the range [1 .. p]
        map<int, long long> maxProfit;
        long long prevMaxProfit = 0;
        for(int i = 0; i < R; ++i){
            int startPoint = rides[i][0];
            int endPoint = rides[i][1];
            long long profit = rides[i][2] + (rides[i][1] - rides[i][0]);
            auto it = maxProfit.upper_bound(startPoint);
            if(it == maxProfit.begin()){
                maxProfit[endPoint] = max(prevMaxProfit, profit);
            }else{
                maxProfit[endPoint] = max(prevMaxProfit, prev(it)->second + profit);
            }
            prevMaxProfit = max(prevMaxProfit, maxProfit[endPoint]);
        }
        
        return prev(maxProfit.end())->second;
    }
};