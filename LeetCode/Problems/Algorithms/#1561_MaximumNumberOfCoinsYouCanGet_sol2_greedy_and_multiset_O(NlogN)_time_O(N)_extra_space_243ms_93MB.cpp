class Solution {
public:
    int maxCoins(vector<int>& piles) {
        multiset<int> pilesMultiset(piles.begin(), piles.end());

        int res = 0;
        while(!pilesMultiset.empty()){
            pilesMultiset.erase(pilesMultiset.begin());
            pilesMultiset.erase(prev(pilesMultiset.end()));
            res += *prev(pilesMultiset.end());
            pilesMultiset.erase(prev(pilesMultiset.end()));
        }

        return res;
    }
};