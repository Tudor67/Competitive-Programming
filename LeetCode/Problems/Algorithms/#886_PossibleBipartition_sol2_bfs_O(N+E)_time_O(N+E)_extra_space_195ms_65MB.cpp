class Solution {
private:
    void bfs(int srcNode, vector<int>& color, const vector<vector<int>>& G, bool& isValid){
        queue<int> q;
        q.push(srcNode);
        color[srcNode] = 0;

        while(!q.empty() && isValid){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                if(color[nextNode] == -1){
                    color[nextNode] = 1 - color[node];
                    q.push(nextNode);
                }else if(color[nextNode] == color[node]){
                    isValid = false;
                }
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
                bfs(srcNode, color, G, isValid);
            }
        }

        return isValid;
    }
};