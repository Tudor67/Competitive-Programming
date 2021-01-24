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
                for(int mask1 = 1; mask1 <= FULL_MASK; ++mask1){
                    for(int mask2 = 1; mask2 <= mask1; ++mask2){
                        minCost[mask1 | mask2][persons] = min(max(minCost[mask1][persons - 1], minCost[mask2][1]),
                                                              minCost[mask1 | mask2][persons]);
                    }
                }
            }
            
            return minCost[FULL_MASK][k];
        }
    }
};