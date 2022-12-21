class Solution {
private:
    void dfs(int node, vector<int>& color, const vector<vector<int>>& G, bool& isValid){
        if(!isValid){
            return;
        }
        for(int nextNode: G[node]){
            if(color[nextNode] == -1){
                color[nextNode] = 1 - color[node];
                dfs(nextNode, color, G, isValid);
            }else if(color[nextNode] == color[node]){
                isValid = false;
            }
        }
    }

public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> G(N + 1);
        for(const vector<int>& D: dislikes){
            int a = D[0];
            int b = D[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> color(N + 1, -1);
        bool isValid = true;
        for(int srcNode = 1; srcNode <= N && isValid; ++srcNode){
            if(color[srcNode] == -1){
                color[srcNode] = 0;
                dfs(srcNode, color, G, isValid);
            }
        }

        return isValid;
    }
};