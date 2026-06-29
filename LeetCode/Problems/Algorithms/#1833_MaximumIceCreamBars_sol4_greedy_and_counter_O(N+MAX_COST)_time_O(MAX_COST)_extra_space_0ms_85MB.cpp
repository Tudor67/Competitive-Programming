class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int MAX_COST = *max_element(costs.begin(), costs.end());

        vector<int> count(MAX_COST + 1);
        for(int cost: costs){
            count[cost] += 1;
        }

        int boughtIceCreams = 0;
        for(int cost = 1; cost <= MAX_COST && coins >= cost; ++cost){
            while(count[cost] > 0 && coins >= cost){
                coins -= cost;
                count[cost] -= 1;
                boughtIceCreams += 1;
            }
        }

        return boughtIceCreams;
    }
};