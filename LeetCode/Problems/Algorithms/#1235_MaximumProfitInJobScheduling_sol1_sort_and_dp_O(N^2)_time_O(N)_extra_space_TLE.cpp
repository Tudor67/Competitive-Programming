class Solution {
private:
    static bool incEndComp(const tuple<int, int, int>& LHS, const tuple<int, int, int>& RHS){
        return (get<1>(LHS) < get<1>(RHS));
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int N = profit.size();
        
        vector<tuple<int, int, int>> startEndProfit(N);
        for(int i = 0; i < N; ++i){
            startEndProfit[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        sort(startEndProfit.begin(), startEndProfit.end(), incEndComp);
        
        // maxProfit[i]: max profit when ith job (ith after sorting) is the last taken job
        vector<int> maxProfit(N + 1);
        
        for(int i = 0; i < N; ++i){
            int iStartTime = get<0>(startEndProfit[i]);
            int iProfit = get<2>(startEndProfit[i]);
            maxProfit[i] = iProfit;
            for(int j = 0; j < i; ++j){
                int jEndTime = get<1>(startEndProfit[j]);
                if(jEndTime <= iStartTime){
                    maxProfit[i] = max(maxProfit[j] + iProfit, maxProfit[i]);
                }else{
                    break;
                }
            }
        }
        
        return *max_element(maxProfit.begin(), maxProfit.end());
    }
};