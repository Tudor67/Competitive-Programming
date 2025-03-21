class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // Step 1: create graph G
        int N = 0;
        unordered_map<string, int> strToNode;

        auto addNewNode = [&](string& s) -> void {
            if(!strToNode.count(s)){
                strToNode[s] = N;
                N += 1;
            }
        };

        for(string& r: recipes){
            addNewNode(r);
        }

        for(vector<string>& v: ingredients){
            for(string& s: v){
                addNewNode(s);
            }
        }

        for(string& s: supplies){
            addNewNode(s);
        }

        vector<vector<int>> G(N);
        vector<int> inDegree(N);
        for(int i = 0; i < (int)recipes.size(); ++i){
            int nextNode = strToNode[recipes[i]];
            for(string& s: ingredients[i]){
                int node = strToNode[s];
                G[node].push_back(nextNode);
                inDegree[nextNode] += 1;
            }
        }

        // Step 2: topological sort
        queue<int> q;
        for(string& s: supplies){
            int node = strToNode[s];
            if(inDegree[node] == 0){
                q.push(node);
            }
        }

        vector<bool> isPossible(N, false);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            isPossible[node] = true;

            for(int nextNode: G[node]){
                inDegree[nextNode] -= 1;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }

        // Step 3: compute result using topologically sorted nodes
        vector<string> res;
        for(string& s: recipes){
            int node = strToNode[s];
            if(isPossible[node]){
                res.push_back(s);
            }
        }

        return res;
    }
};