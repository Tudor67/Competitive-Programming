class Solution {
private:
    void dfs(int node, vector<bool>& vis, vector<bool>& is_in_stack, const vector<vector<pair<int, int>>>& G,
             int cur_max_idx, int& answer_idx, bool& cycle_found){
        vis[node] = true;
        is_in_stack[node] = true;
        
        for(const pair<int, int>& P: G[node]){
            int next_node = P.first;
            int idx = P.second;
            
            if(is_in_stack[next_node]){
                cycle_found = true;
                answer_idx = max(idx, cur_max_idx);
            }else if(!vis[next_node]){
                dfs(next_node, vis, is_in_stack, G, max(idx, cur_max_idx), answer_idx, cycle_found);
            }
        }
        
        is_in_stack[node] = false;
    }
    
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& arcs) {
        const int N = arcs.size();
        
        // build the graph
        vector<vector<pair<int, int>>> g(N + 1);
        vector<int> in_degree(N + 1, 0);
        for(int i = 0; i < N; ++i){
            g[arcs[i][0]].push_back({arcs[i][1], i});
            in_degree[arcs[i][1]] += 1;
        }
        
        // find the root of the tree (if possible)
        int tree_root = -1;
        for(int node = 1; node <= N; ++node){
            if(in_degree[node] == 0){
                tree_root = node;
                break;
            }
        }
        
        // solve
        vector<int> answer;
        if(tree_root >= 1){
            // case 1: root + cyclic/non-cyclic graph
            int special_node = -1;
            for(int node = 1; node <= N; ++node){
                if(in_degree[node] == 2){
                    special_node = node;
                }
            }
            
            // Important: special_node is part of the final answer
            // case 1.1: root + cyclic graph => remove the last arc of the cycle
            // case 1.2: root + non-cyclic graph => remove the arc with max_idx
            vector<bool> vis(N + 1, false);
            vis[special_node] = true;
            queue<int> q;
            q.push(special_node);
            while(!q.empty() && answer.empty()){
                int node = q.front();
                q.pop();
                
                for(const pair<int, int>& P: g[node]){
                    int next_node = P.first;
                    if(vis[next_node]){
                        // case 1.1: we found a cycle => remove the last arc of the cycle
                        answer = {node, next_node};
                    }else{
                        vis[next_node] = true;
                        q.push(next_node);
                    }
                }
            }
            
            if(answer.empty()){
                // case 1.2: we didn't find a cycle => remove the arc with max_idx
                for(int i = 0; i < N; ++i){
                    if(arcs[i][1] == special_node){
                        answer = arcs[i];
                    }
                }
            }
        }else{
            // case 2: no root + cyclic graph => remove the arc with max_idx (which is inside the cycle, not outside)
            //         the initial root is inside the cycle (not outside)
            vector<bool> vis(N + 1, false);
            vector<bool> is_in_stack(N + 1, false);
            int cur_max_idx = -1;
            int answer_idx = -1;
            bool cycle_found = false;
            for(int node = 1; !cycle_found && node <= N; ++node){
                if(!vis[node]){
                    dfs(node, vis, is_in_stack, g, cur_max_idx, answer_idx, cycle_found);
                }
            }
            answer = arcs[answer_idx];
        }
        
        return answer;
    }
};