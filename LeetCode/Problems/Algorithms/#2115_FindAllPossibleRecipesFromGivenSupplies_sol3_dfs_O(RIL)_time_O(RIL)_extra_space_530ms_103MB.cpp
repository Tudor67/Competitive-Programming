class Solution {
private:
    bool dfs(const string& RECIPE, unordered_map<string, vector<string>>& g, unordered_map<string, bool>& isPossible){
        if(isPossible.count(RECIPE)){
            return isPossible[RECIPE];
        }
        // if RECIPE is part of a cycle then isPossible[RECIPE] == false
        isPossible[RECIPE] = false;
        bool ok = true;
        for(const string& NEXT_RECIPE: g[RECIPE]){
            if(RECIPE == NEXT_RECIPE || !dfs(NEXT_RECIPE, g, isPossible)){
                ok = false;
                break;
            }
        }
        isPossible[RECIPE] = ok;
        return isPossible[RECIPE];
    }
    
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        const int R = recipes.size();
        
        unordered_set<string> recipesSet(recipes.begin(), recipes.end());
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end());
        
        unordered_map<string, vector<string>> g;
        for(int i = 0; i < R; ++i){
            for(const string& INGREDIENT: ingredients[i]){
                if(suppliesSet.count(INGREDIENT)){
                    // skip ingredients we already have
                    continue;
                }else{
                    if(recipesSet.count(INGREDIENT)){
                        // recipes[i] needs another recipes[j] == INGREDIENT
                        g[recipes[i]].push_back(INGREDIENT);
                    }else{
                        // self-loop for recipes[i] => we cannot create recipes[i]
                        g[recipes[i]].push_back(recipes[i]);
                    }
                }
            }
        }
        
        unordered_map<string, bool> isPossible;
        vector<string> answer;
        for(int i = 0; i < R; ++i){
            isPossible[recipes[i]] = dfs(recipes[i], g, isPossible);
            if(isPossible[recipes[i]]){
                answer.push_back(recipes[i]);
            }
        }
        
        return answer;
    }
};