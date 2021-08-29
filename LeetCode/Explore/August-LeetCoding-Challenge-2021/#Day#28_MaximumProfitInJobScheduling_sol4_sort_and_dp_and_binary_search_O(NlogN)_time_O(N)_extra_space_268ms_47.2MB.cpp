class Solution {
private:
    static bool incEndTimeSortComp(const tuple<int, int, int>& LHS, const tuple<int, int, int>& RHS){
        int lhsEndTime = get<1>(LHS);
        int rhsEndTime = get<1>(RHS);
        return (lhsEndTime < rhsEndTime);
    }
    
    static bool incEndTimeUBComp(const int& VAL, const tuple<int, int, int>& IT){
        int endTime = get<1>(IT);
        return (VAL < endTime);
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int N = startTime.size();
        
        vector<tuple<int, int, int>> jobs(N);
        for(int i = 0; i < N; ++i){
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end(), incEndTimeSortComp);
        
        // maxProfit[i]: max profit when the last taken job is from jobs[0 .. i]
        vector<int> maxProfit(N);
        maxProfit[0] = get<2>(jobs[0]);
        for(int i = 1; i < N; ++i){
            int iStartTime = get<0>(jobs[i]);
            int iProfit = get<2>(jobs[i]);
            int j = upper_bound(jobs.begin(), jobs.begin() + i, iStartTime, incEndTimeUBComp) - jobs.begin() - 1;
            if(j >= 0){
                maxProfit[i] = max(maxProfit[i - 1], maxProfit[j] + iProfit);
            }else{
                maxProfit[i] = max(maxProfit[i - 1], iProfit);
            }
        }
        
        return maxProfit[N - 1];
    }
};