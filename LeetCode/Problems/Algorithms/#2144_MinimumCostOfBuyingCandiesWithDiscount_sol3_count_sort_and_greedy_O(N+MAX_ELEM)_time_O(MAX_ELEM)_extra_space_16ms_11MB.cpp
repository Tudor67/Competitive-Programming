class Solution {
public:
    int minimumCost(vector<int>& cost) {
        const int N = cost.size();
        const int MAX_ELEM = *max_element(cost.begin(), cost.end());
        
        vector<int> count(MAX_ELEM + 1);
        for(int elem: cost){
            count[elem] += 1;
        }
        
        int idx = 0;
        for(int elem = MAX_ELEM; elem >= 0; --elem){
            while(count[elem] > 0){
                count[elem] -= 1;
                cost[idx] = elem;
                idx += 1;
            }
        }
        
        int minTotalCost = 0;
        for(int i = 0; i < N; ++i){
            if(i % 3 != 2){
                minTotalCost += cost[i];
            }
        }
        
        return minTotalCost;
    }
};