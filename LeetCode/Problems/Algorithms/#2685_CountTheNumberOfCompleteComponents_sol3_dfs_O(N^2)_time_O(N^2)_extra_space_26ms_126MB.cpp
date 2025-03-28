class Solution {
private:
    void dfs(int node, vector<bool>& vis, vector<vector<bool>>& isAdj, vector<int>& cc){
        const int N = vis.size();
        if(vis[node]){
            return;
        }
        vis[node] = true;
        cc.push_back(node);
        for(int nextNode = 0; nextNode < N; ++nextNode){
            if(isAdj[node][nextNode]){
                dfs(nextNode, vis, isAdj, cc);
            }
        }
    }

public:
    int countCompleteComponents(int N, vector<vector<int>>& edges) {
        vector<vector<bool>> isAdj(N, vector<bool>(N, false));
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            isAdj[a][b] = true;
            isAdj[b][a] = true;
        }

        int completeConnectedComponents = 0;
        vector<bool> vis(N, false);
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                vector<int> cc;
                dfs(node, vis, isAdj, cc);

                bool isComplete = true;
                for(int a: cc){
                    for(int b: cc){
                        if(a != b && !isAdj[a][b]){
                            isComplete = false;
                            break;
                        }
                    }
                }

                if(isComplete){
                    completeConnectedComponents += 1;
                }
            }
        }

        return completeConnectedComponents;
    }
};