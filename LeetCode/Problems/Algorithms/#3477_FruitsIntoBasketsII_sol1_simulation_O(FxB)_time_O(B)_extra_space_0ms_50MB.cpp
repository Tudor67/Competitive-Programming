class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int F = fruits.size();
        const int B = baskets.size();

        int res = 0;
        vector<int> currBaskets = baskets;

        for(int i = 0; i < F; ++i){
            int basketIndex = -1;
            for(int j = 0; j < B && basketIndex < 0; ++j){
                if(fruits[i] <= currBaskets[j]){
                    basketIndex = j;
                }
            }

            if(basketIndex >= 0){
                currBaskets[basketIndex] = 0;
            }else{
                res += 1;
            }
        }

        return res;
    }
};