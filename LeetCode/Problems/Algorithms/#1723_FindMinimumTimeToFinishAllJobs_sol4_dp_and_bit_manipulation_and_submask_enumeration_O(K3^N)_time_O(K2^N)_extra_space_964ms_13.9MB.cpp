class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        if(k == 1){
            return accumulate(jobs.begin(), jobs.end(), 0);
        }else if(k == jobs.size()){
            return *max_element(jobs.begin(), jobs.end());
        }else{
            const int N = jobs.size();
            const int FULL_MASK = (1 << N) - 1;
            vector<vector<int>> minCost(FULL_MASK + 1, vector<int>(k + 1, INT_MAX));
            // minCost[mask][personsCount] - minimum cost to complete all jobs from mask (only jobs[bit], where bit is 1)
            //                               using personsCount persons
            
            for(int mask = 1; mask <= FULL_MASK; ++mask){
                int cost = 0;
                for(int bit = 0; bit < N; ++bit){
                    if((mask >> bit) & 1){
                        cost += jobs[bit];
                    }
                }
                minCost[mask][1] = cost;
            }
            
            for(int persons = 2; persons <= k; ++persons){
                for(int mask = 1; mask <= FULL_MASK; ++mask){
                    for(int subMask = mask; subMask >= 1; subMask = (subMask - 1) & mask){
                        minCost[mask][persons] = min(max(minCost[mask ^ subMask][persons - 1], minCost[subMask][1]),
                                                     minCost[mask][persons]);
                    }
                }
            }
            
            return minCost[FULL_MASK][k];
        }
    }
};