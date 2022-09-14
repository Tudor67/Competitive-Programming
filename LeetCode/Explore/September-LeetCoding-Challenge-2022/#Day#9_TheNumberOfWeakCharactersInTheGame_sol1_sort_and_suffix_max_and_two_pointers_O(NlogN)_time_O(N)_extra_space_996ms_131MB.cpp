class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        const int N = properties.size();
        
        vector<pair<int, int>> sortedAttackDefense(N);
        for(int i = 0; i < N; ++i){
            sortedAttackDefense[i] = {properties[i][0], properties[i][1]};
        }
        
        sort(sortedAttackDefense.begin(), sortedAttackDefense.end());
        
        vector<int> suffMaxDefense(N);
        suffMaxDefense[N - 1] = sortedAttackDefense[N - 1].second;
        for(int i = N - 2; i >= 0; --i){
            suffMaxDefense[i] = max(sortedAttackDefense[i].second, suffMaxDefense[i + 1]);
        }
        
        int weakCharacters = 0;
        int j = 0;
        for(int i = 0; i < N; ++i){
            while(j < N && sortedAttackDefense[i].first == sortedAttackDefense[j].first){
                j += 1;
            }
            if(j < N && sortedAttackDefense[i].second < suffMaxDefense[j]){
                weakCharacters += 1;
            }
        }
        
        return weakCharacters;
    }
};