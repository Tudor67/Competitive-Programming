class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        const int R = recipes.size();
        
        unordered_map<string, vector<string>> g;
        unordered_map<string, int> inDegree;
        for(int i = 0; i < R; ++i){
            const string& RECIPE = recipes[i];
            for(const string& INGREDIENT: ingredients[i]){
                g[INGREDIENT].push_back(RECIPE);
                inDegree[RECIPE] += 1;
            }
        }
        
        queue<string> q;
        for(const string& SUPPLY: supplies){
            if(g.count(SUPPLY)){
                q.push(SUPPLY);
            }
        }
        
        while(!q.empty()){
            string ingredient = q.front();
            q.pop();
            
            for(const string& NEXT_INGREDIENT: g[ingredient]){
                inDegree[NEXT_INGREDIENT] -= 1;
                if(inDegree[NEXT_INGREDIENT] == 0){
                    q.push(NEXT_INGREDIENT);
                }
            }
        }
        
        vector<string> answer;
        for(int i = 0; i < R; ++i){
            if(inDegree[recipes[i]] == 0){
                answer.push_back(recipes[i]);
            }
        }
        
        return answer;
    }
};