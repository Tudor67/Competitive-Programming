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
        
        // maxProfit[i]: max profit when the last taken job is from jobs[0..i] (jobs is sorted)
        vector<int> maxProfit(N + 1);
        
        for(int i = 0; i < N; ++i){
            int iStartTime = get<0>(startEndProfit[i]);
            int iProfit = get<2>(startEndProfit[i]);
            maxProfit[i] = iProfit;
            if(i >= 1){
                maxProfit[i] = max(maxProfit[i - 1], iProfit);
            }
            int j = N - 1;
            while(j >= 0 && get<1>(startEndProfit[j]) > iStartTime){
                j -= 1;
            }
            if(j >= 0){
                int jEndTime = get<1>(startEndProfit[j]);
                if(jEndTime <= iStartTime){
                    maxProfit[i] = max(maxProfit[j] + iProfit, maxProfit[i]);
                }
            }
        }
        
        return *max_element(maxProfit.begin(), maxProfit.end());
    }
};