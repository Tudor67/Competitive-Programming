class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const int S = spells.size();
        const int P = potions.size();

        vector<int> sortedPotions = potions;
        sort(sortedPotions.begin(), sortedPotions.end());

        vector<int> pairs(S);
        for(int i = 0; i < S; ++i){
            long long threshold = (success + spells[i] - 1) / spells[i];
            pairs[i] = sortedPotions.end() - lower_bound(sortedPotions.begin(), sortedPotions.end(), threshold);
        }

        return pairs;
    }
};