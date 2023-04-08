class Solution {
private:
    using Graph = vector<vector<int>>;
    
    void dfs1(int parentNode, int node, const Graph& G, set<pair<int, int>>& guessSet, vector<int>& subtreeGuessCount){
        for(int childNode: G[node]){
            if(childNode != parentNode){
                dfs1(node, childNode, G, guessSet, subtreeGuessCount);
                subtreeGuessCount[node] += subtreeGuessCount[childNode];
                subtreeGuessCount[node] += guessSet.count({node, childNode});
            }
        }
    }
    
    void dfs2(int parentNode, int node, const Graph& G, set<pair<int, int>>& guessSet, vector<int>& rootGuessCount){
        if(parentNode >= 0){
            rootGuessCount[node] = rootGuessCount[parentNode] - guessSet.count({parentNode, node})
                                                              + guessSet.count({node, parentNode});
        }
        
        for(int childNode: G[node]){
            if(childNode != parentNode){
                dfs2(node, childNode, G, guessSet, rootGuessCount);
            }
        }
    }
    
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        const int E = edges.size();
        const int N = E + 1;
        
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        set<pair<int, int>> guessSet;
        for(const vector<int>& EDGE: guesses){
            int a = EDGE[0];
            int b = EDGE[1];
            guessSet.insert({a, b});
        }
        
        vector<int> subtreeGuessCount(N);
        dfs1(-1, 0, G, guessSet, subtreeGuessCount);
        
        vector<int> rootGuessCount(N);
        rootGuessCount[0] = subtreeGuessCount[0];
        dfs2(-1, 0, G, guessSet, rootGuessCount);
        
        int validRoots = 0;
        for(int node = 0; node < N; ++node){
            if(rootGuessCount[node] >= k){
                validRoots += 1;
            }
        }
        
        return validRoots;
    }
};