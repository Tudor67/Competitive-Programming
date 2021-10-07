class Solution {
private:
    static const int INF = 1e8;
    
    int vectorToHash(const vector<int>& V, const int& BASE){
        int vectorHash = 0;
        for(int elem: V){
            vectorHash = BASE * vectorHash + elem;
        }
        return vectorHash;
    }
    
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, const int& BASE, int* memo){
        if(*min_element(needs.begin(), needs.end()) < 0){
            return INF;
        }
        
        if(*max_element(needs.begin(), needs.end()) == 0){
            return 0;
        }
        
        int needsHash = vectorToHash(needs, BASE);
        if(memo[needsHash] != -1){
            return memo[needsHash];
        }
        
        const int S = special.size();
        const int N = needs.size();
        
        int minCost = 0;
        for(int j = 0; j < N; ++j){
            minCost += (price[j] * needs[j]);
        }
        
        for(int i = 0; i < S; ++i){
            for(int j = 0; j < N; ++j){
                needs[j] -= special[i][j];
            }
            int cost = special[i].back() + solve(price, special, needs, BASE, memo);
            minCost = min(minCost, cost);
            for(int j = 0; j < N; ++j){
                needs[j] += special[i][j];
            }
        }
        
        memo[needsHash] = minCost;
        return minCost;
    }
              
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        const int BASE = 1 + *max_element(needs.begin(), needs.end());
        const int MAX_HASH_VALUE = vectorToHash(needs, BASE);
        int memo[MAX_HASH_VALUE + 1];
        fill(memo, memo + MAX_HASH_VALUE + 1, -1);
        return solve(price, special, needs, BASE, memo);
    }
};