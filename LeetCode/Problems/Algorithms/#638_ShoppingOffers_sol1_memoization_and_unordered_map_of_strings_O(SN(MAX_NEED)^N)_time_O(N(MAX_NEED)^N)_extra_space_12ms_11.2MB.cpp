class Solution {
private:
    static const int INF = 1e8;
    
    string vectorToString(vector<int>& v){
        string s;
        for(int elem: v){
            s += "#";
            s += to_string(elem);
        }
        return s;
    }
    
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& memo){
        if(*min_element(needs.begin(), needs.end()) < 0){
            return INF;
        }
        
        if(*max_element(needs.begin(), needs.end()) == 0){
            return 0;
        }
        
        string needsStr = vectorToString(needs);
        if(memo.count(needsStr)){
            return memo[needsStr];
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
            int cost = special[i].back() + solve(price, special, needs, memo);
            minCost = min(minCost, cost);
            for(int j = 0; j < N; ++j){
                needs[j] += special[i][j];
            }
        }
        
        memo[needsStr] = minCost;
        return minCost;
    }
              
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> memo;
        return solve(price, special, needs, memo);
    }
};