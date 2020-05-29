class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> neighbors(N + 1);
        for(const vector<int>& p: dislikes){
            neighbors[p[0]].push_back(p[1]);
            neighbors[p[1]].push_back(p[0]);
        }
        
        vector<bool> vis(N + 1, false);
        vector<bool> color(N + 1, false);
        queue<int> q;
        
        bool is_ok = true;
        for(int node = 1; is_ok && node <= N; ++node){
            if(!neighbors[node].empty() && !vis[node]){
                q.push(node);
                vis[node] = true;
                color[node] = true;
                
                while(!q.empty() && is_ok){
                    int node = q.front();
                    q.pop();
                    for(int next_node: neighbors[node]){
                        if(!vis[next_node]){
                            q.push(next_node);
                            vis[next_node] = true;
                            color[next_node] = !color[node];
                        }else{
                            if(color[next_node] == color[node]){
                                is_ok = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        return is_ok;
    }
};