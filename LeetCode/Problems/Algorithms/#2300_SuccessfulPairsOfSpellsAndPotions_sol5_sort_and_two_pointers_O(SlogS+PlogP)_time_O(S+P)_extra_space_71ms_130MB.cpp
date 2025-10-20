class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const int S = spells.size();
        const int P = potions.size();

        vector<int> spellsIndices(S);
        iota(spellsIndices.begin(), spellsIndices.end(), 0);
        sort(spellsIndices.begin(), spellsIndices.end(),
             [&](int lhs, int rhs){
                return (spells[lhs] < spells[rhs]);
             });

        vector<int> sortedPotions = potions;
        sort(sortedPotions.begin(), sortedPotions.end());

        vector<int> pairs(S);
        int potionIndex = P - 1;
        for(int spellIndex: spellsIndices){
            long long spell = spells[spellIndex];
            while(potionIndex >= 0 && spell * sortedPotions[potionIndex] >= success){
                potionIndex -= 1;
            }
            pairs[spellIndex] = P - 1 - potionIndex;
        }

        return pairs;
    }
};