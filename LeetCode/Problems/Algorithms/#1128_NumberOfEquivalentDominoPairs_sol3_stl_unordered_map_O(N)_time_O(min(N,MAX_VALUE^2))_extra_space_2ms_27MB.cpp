class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        const int N = dominoes.size();

        int goodPairs = 0;

        auto pairHash = [](pair<int, int> p) -> size_t {
            size_t lhs = p.first;
            size_t rhs = p.second;
            return ((lhs << 4) | rhs);
        };
        unordered_map<pair<int, int>, int, decltype(pairHash)> freq;

        for(vector<int>& domino: dominoes){
            int a = domino[0];
            int b = domino[1];

            if(a > b){
                swap(a, b);
            }

            goodPairs += freq[{a, b}];

            freq[{a, b}] += 1;
        }

        return goodPairs;
    }
};