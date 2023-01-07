class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int N = costs.size();
        const int MAX_COST = *max_element(costs.begin(), costs.end());

        vector<int> count(MAX_COST + 1);
        for(int cost: costs){
            count[cost] += 1;
        }

        int res = 0;
        for(int cost = 1; cost <= MAX_COST; ++cost){
            while(count[cost] > 0 && cost <= coins){
                count[cost] -= 1;
                coins -= cost;
                res += 1;
            }
        }

        return res;
    }
};