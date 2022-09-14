class Solution {
private:
    static bool incAttackDecDefenseComp(const pair<int, int>& LHS, const pair<int, int>& RHS){
        int lhsAttack = LHS.first;
        int lhsDefense = LHS.second;
        int rhsAttack = RHS.first;
        int rhsDefense = RHS.second;
        return (lhsAttack < rhsAttack || (lhsAttack == rhsAttack && lhsDefense > rhsDefense));
    }
    
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        const int N = properties.size();
        
        vector<pair<int, int>> incAttackDecDefense(N);
        for(int i = 0; i < N; ++i){
            incAttackDecDefense[i] = {properties[i][0], properties[i][1]};
        }
        
        sort(incAttackDecDefense.begin(), incAttackDecDefense.end(), incAttackDecDefenseComp);
        
        int weakCharacters = 0;
        int suffMaxDefense = incAttackDecDefense[N - 1].second;
        for(int i = N - 2; i >= 0 ; --i){
            if(incAttackDecDefense[i].second < suffMaxDefense){
                weakCharacters += 1;
            }
            suffMaxDefense = max(suffMaxDefense, incAttackDecDefense[i].second);
        }
        
        return weakCharacters;
    }
};