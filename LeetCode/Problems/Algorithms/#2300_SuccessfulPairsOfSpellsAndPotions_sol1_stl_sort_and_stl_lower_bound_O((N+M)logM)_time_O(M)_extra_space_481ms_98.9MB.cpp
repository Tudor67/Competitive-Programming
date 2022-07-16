class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const int N = spells.size();
        const int M = potions.size();
        
        vector<int> sortedPotions = potions;
        sort(sortedPotions.begin(), sortedPotions.end());
        
        vector<int> pairs(N);
        for(int i = 0; i < N; ++i){
            long long minValidPotion = (success + spells[i] - 1) / spells[i];
            int j = lower_bound(sortedPotions.begin(), sortedPotions.end(), minValidPotion) - sortedPotions.begin();
            pairs[i] = M - j;
        }
        
        return pairs;
    }
};