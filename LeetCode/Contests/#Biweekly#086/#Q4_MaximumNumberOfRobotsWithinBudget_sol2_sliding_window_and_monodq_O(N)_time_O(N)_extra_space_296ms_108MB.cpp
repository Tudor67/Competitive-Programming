class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        const int N = chargeTimes.size();
        
        int res = 0;
        int l = 0;
        long long wCostSum = 0;
        deque<int> dq;
        for(int r = 0; r < N; ++r){
            wCostSum += runningCosts[r];
            while(!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[r]){
                dq.pop_back();
            }
            dq.push_back(r);
            while(l <= r && chargeTimes[dq.front()] + (r - l + 1) * wCostSum > budget){
                if(l == dq.front()){
                    dq.pop_front();
                }
                wCostSum -= runningCosts[l];
                l += 1;
            }
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};