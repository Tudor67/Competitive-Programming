class Solution {
private:
    void dfs(const string& S, int node, vector<bool>& vis,
             string& groupChars, vector<int>& groupIndices,
             vector<vector<int>>& neighbors){
        if(!vis[node]){
            vis[node] = true;
            groupChars.push_back(S[node]);
            groupIndices.push_back(node);
            for(int nextNode: neighbors[node]){
                dfs(S, nextNode, vis, groupChars, groupIndices, neighbors);
            }
        }
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if(pairs.empty()){
            return s;
        }
        
        const int N = s.length();
        
        vector<vector<int>> neighbors(N);
        for(const vector<int>& P: pairs){
            neighbors[P[0]].push_back(P[1]);
            neighbors[P[1]].push_back(P[0]);
        }
        
        vector<bool> vis(N, false);
        string groupChars;
        vector<int> groupIndices;
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                groupChars.clear();
                groupIndices.clear();
                
                dfs(s, node, vis, groupChars, groupIndices, neighbors);
                
                sort(groupChars.begin(), groupChars.end());
                sort(groupIndices.begin(), groupIndices.end());
                
                for(int i = 0; i < (int)groupChars.size(); ++i){
                    s[groupIndices[i]] = groupChars[i];
                }
            }
        }
        
        return s;
    }
};