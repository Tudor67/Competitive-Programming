class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        const int R = recipes.size();
        
        unordered_map<string, int> idxOf;
        for(const string& RECIPE: recipes){
            int idx = idxOf.size();
            idxOf[RECIPE] = idx;
        }
        
        for(const vector<string>& RECIPE_INGREDIENTS: ingredients){
            for(const string& INGREDIENT: RECIPE_INGREDIENTS){
                if(!idxOf.count(INGREDIENT)){
                    int idx = idxOf.size();
                    idxOf[INGREDIENT] = idx;
                }
            }
        }
        
        for(const string& SUPPLY: supplies){
            if(!idxOf.count(SUPPLY)){
                int idx = idxOf.size();
                idxOf[SUPPLY] = idx;
            }
        }
        
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> inDegree;
        for(int i = 0; i < R; ++i){
            int recipeIdx = idxOf[recipes[i]];
            for(const string& INGREDIENT: ingredients[i]){
                int ingredientIdx = idxOf[INGREDIENT];
                g[ingredientIdx].push_back(recipeIdx);
                inDegree[recipeIdx] += 1;
            }
        }
        
        queue<int> q;
        for(const string& SUPPLY: supplies){
            q.push(idxOf[SUPPLY]);
        }
        
        while(!q.empty()){
            int ingredientIdx = q.front();
            q.pop();
            
            for(int nextIngredientIdx: g[ingredientIdx]){
                inDegree[nextIngredientIdx] -= 1;
                if(inDegree[nextIngredientIdx] == 0){
                    q.push(nextIngredientIdx);
                }
            }
        }
        
        vector<string> answer;
        for(int i = 0; i < R; ++i){
            if(inDegree[idxOf[recipes[i]]] == 0){
                answer.push_back(recipes[i]);
            }
        }
        
        return answer;
    }
};