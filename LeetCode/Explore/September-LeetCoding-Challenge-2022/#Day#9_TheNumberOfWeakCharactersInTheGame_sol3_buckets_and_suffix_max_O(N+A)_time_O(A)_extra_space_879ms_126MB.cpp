class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        const int N = properties.size();
        
        int maxAttack = properties[0][0];
        for(int i = 0; i < N; ++i){
            int attack = properties[i][0];
            maxAttack = max(maxAttack, attack);
        }
        
        vector<int> maxDefenseFor(maxAttack + 2);
        for(int i = 0; i < N; ++i){
            int attack = properties[i][0];
            int defense = properties[i][1];
            maxDefenseFor[attack] = max(maxDefenseFor[attack], defense);
        }
        
        for(int attack = maxAttack; attack >= 0; --attack){
            maxDefenseFor[attack] = max(maxDefenseFor[attack], maxDefenseFor[attack + 1]);
        }
        
        int weakCharacters = 0;
        for(int i = 0; i < N; ++i){
            int attack = properties[i][0];
            int defense = properties[i][1];
            if(defense < maxDefenseFor[attack + 1]){
                weakCharacters += 1;
            }
        }
        
        return weakCharacters;
    }
};