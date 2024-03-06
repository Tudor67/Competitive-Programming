class Solution {
private:
    int computeMaxAlloys(const vector<int>& MACHINE_NEED, vector<int>& stock, vector<int>& cost, int budget){
        const int N = stock.size();

        long long l = 0;
        long long r = budget + *max_element(stock.begin(), stock.end());

        while(l != r){
            long long mid = (l + r + 1) / 2;

            long long totalCost = 0;
            for(int i = 0; i < N && totalCost <= budget; ++i){
                if(stock[i] < mid * MACHINE_NEED[i]){
                    long long toBuy = mid * MACHINE_NEED[i] - stock[i];
                    totalCost += (toBuy * cost[i]);
                }
            }
            
            if(totalCost <= budget){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }

public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int res = 0;
        for(int i = 0; i < k; ++i){
            res = max(res, computeMaxAlloys(composition[i], stock, cost, budget));
        }
        return res;
    }
};