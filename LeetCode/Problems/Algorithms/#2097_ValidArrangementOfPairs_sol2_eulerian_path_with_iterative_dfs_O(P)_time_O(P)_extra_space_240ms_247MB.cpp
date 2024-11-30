class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> G;
        unordered_map<int, int> inOutDiff;
        for(const vector<int>& EDGE: pairs){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            inOutDiff[a] -= 1;
            inOutDiff[b] += 1;
        }

        int startNode = pairs[0][0];
        for(auto& [node, diff]: inOutDiff){
            if(diff == -1){
                startNode = node;
            }
        }

        vector<int> path;
        stack<int> st;
        st.push(startNode);
        
        while(!st.empty()){
            int node = st.top();
            if(G[node].empty()){
                path.push_back(node);
                st.pop();
            }else{
                int nextNode = G[node].back();
                G[node].pop_back();
                st.push(nextNode);
            }
        }

        reverse(path.begin(), path.end());

        vector<vector<int>> res;
        for(int i = 1; i < (int)path.size(); ++i){
            res.push_back({path[i - 1], path[i]});
        }

        return res;
    }
};