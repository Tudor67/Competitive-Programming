class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        unordered_set<string> available(supplies.begin(), supplies.end());

        bool updated = true;
        while(updated){
            updated = false;

            for(int i = 0; i < (int)recipes.size(); ++i){
                if(available.count(recipes[i])){
                    continue;
                }

                bool isPossible = true;
                for(string& ingr: ingredients[i]){
                    if(!available.count(ingr)){
                        isPossible = false;
                        break;
                    }
                }

                if(isPossible){
                    available.insert(recipes[i]);
                    res.push_back(recipes[i]);
                    updated = true;
                }
            }
        }

        return res;
    }
};