class Solution {
private:
    struct PairHash {
        size_t operator()(pair<int, int> p) const {
            size_t lhs = p.first;
            size_t rhs = p.second;
            return ((lhs << 4) | rhs);
        }
    };

public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        const int N = dominoes.size();

        int goodPairs = 0;
        unordered_map<pair<int, int>, int, PairHash> freq;

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