class Solution {
private:
    void dfs(int node, vector<vector<int>>& neighbors,
             vector<int>& groupIdOf, int groupId,
             vector<string>& charsOf, const string& S){
        if(groupIdOf[node] == 0){
            groupIdOf[node] = groupId;
            charsOf[groupId].push_back(S[node]);
            for(int nextNode: neighbors[node]){
                dfs(nextNode, neighbors, groupIdOf, groupId, charsOf, S);
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
        
        vector<int> groupIdOf(N);
        int groupId = 0;
        vector<string> charsOf(N);
        for(int node = 0; node < N; ++node){
            if(groupIdOf[node] == 0){
                ++groupId;
                dfs(node, neighbors, groupIdOf, groupId, charsOf, s);
            }
        }
        
        for(int i = 1; i <= groupId; ++i){
            sort(charsOf[i].begin(), charsOf[i].end());
        }
        
        for(int i = N - 1; i >= 0; --i){
            if(groupIdOf[i] >= 1){
                s[i] = charsOf[groupIdOf[i]].back();
                charsOf[groupIdOf[i]].pop_back();
            }
        }
        
        return s;
    }
};