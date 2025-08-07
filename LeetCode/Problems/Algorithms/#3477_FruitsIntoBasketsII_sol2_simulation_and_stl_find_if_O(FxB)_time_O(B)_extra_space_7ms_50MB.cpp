class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int F = fruits.size();
        const int B = baskets.size();

        int res = 0;
        vector<int> currBaskets = baskets;

        for(int i = 0; i < F; ++i){
            int basketIndex = find_if(currBaskets.begin(), currBaskets.end(),
                                      [&](int basket){ return (fruits[i] <= basket); })
                              - currBaskets.begin();
            if(basketIndex < B){
                currBaskets[basketIndex] = 0;
            }else{
                res += 1;
            }
        }

        return res;
    }
};