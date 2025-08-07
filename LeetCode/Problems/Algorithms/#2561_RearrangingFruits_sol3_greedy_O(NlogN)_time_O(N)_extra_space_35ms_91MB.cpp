class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        const int N = basket1.size();
        const int MIN1 = *min_element(basket1.begin(), basket1.end());
        const int MIN2 = *min_element(basket2.begin(), basket2.end());

        unordered_map<int, int> balance;
        for(int i = 0; i < N; ++i){
            balance[basket1[i]] += 1;
            balance[basket2[i]] -= 1;
        }

        vector<int> v;
        for(auto& [f, fBalance]: balance){
            if(fBalance % 2 == 0){
                v.resize(v.size() + abs(fBalance / 2), f);
            }else{
                return -1;
            }
        }

        sort(v.begin(), v.end());

        long long res = 0;
        for(int i = 0; i < (int)v.size() / 2; ++i){
            int costOpt1 = v[i];
            int costOpt2 = min(MIN1, MIN2) * 2;
            res += min(costOpt1, costOpt2);
        }

        return res;
    }
};