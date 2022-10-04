class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        const int N = chargeTimes.size();
        
        int res = 0;
        int l = 0;
        long long wCostSum = 0;
        priority_queue<pair<int, int>> timeIdxHeap;
        for(int r = 0; r < N; ++r){
            wCostSum += runningCosts[r];
            timeIdxHeap.emplace(chargeTimes[r], r);
            while(l <= r && timeIdxHeap.top().first + (r - l + 1) * wCostSum > budget){
                while(!timeIdxHeap.empty() && timeIdxHeap.top().second <= l){
                    timeIdxHeap.pop();
                }
                wCostSum -= runningCosts[l];
                l += 1;
            }
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};