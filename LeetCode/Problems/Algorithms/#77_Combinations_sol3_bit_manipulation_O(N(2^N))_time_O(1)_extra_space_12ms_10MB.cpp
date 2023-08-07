class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        const int FULL_MASK = (1 << n) - 1;

        vector<vector<int>> combinations;
        
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            if(__builtin_popcount(mask) == k){
                combinations.push_back({});
                for(int bit = 0; bit < n; ++bit){
                    if((mask >> bit) & 1){
                        combinations.back().push_back(bit + 1);
                    }
                }
            }
        }

        return combinations;
    }
};