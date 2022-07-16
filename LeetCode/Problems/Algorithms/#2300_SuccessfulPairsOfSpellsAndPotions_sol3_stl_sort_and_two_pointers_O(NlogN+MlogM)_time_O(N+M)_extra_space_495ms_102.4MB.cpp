class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const int N = spells.size();
        const int M = potions.size();
        
        // sort
        vector<pair<int, int>> sortedSpellsIndices(N);
        for(int i = 0; i < N; ++i){
            sortedSpellsIndices[i] = {spells[i], i};
        }
        sort(sortedSpellsIndices.begin(), sortedSpellsIndices.end());
        
        vector<int> sortedPotions = potions;
        sort(sortedPotions.begin(), sortedPotions.end());
        
        // two pointers
        vector<int> pairs(N);
        int j = M - 1;
        for(int i = 0; i < N; ++i){
            long long currentSpell = sortedSpellsIndices[i].first;
            int spellIndex = sortedSpellsIndices[i].second;
            while(j >= 0 && currentSpell * sortedPotions[j] >= success){
                j -= 1;
            }
            pairs[spellIndex] = M - 1 - j;
        }
        
        return pairs;
    }
};