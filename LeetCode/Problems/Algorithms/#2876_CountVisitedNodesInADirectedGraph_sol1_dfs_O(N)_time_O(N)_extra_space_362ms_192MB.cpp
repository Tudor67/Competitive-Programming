class Solution {
private:
    void dfs(int node, vector<int>& st, vector<bool>& inStack, vector<int>& edges, vector<int>& res){
        if(res[node] >= 1){
            return;
        }
        
        st.push_back(node);
        inStack[node] = true;
        
        int nextNode = edges[node];
        if(inStack[nextNode]){
            int startIndex = find(st.begin(), st.end(), nextNode) - st.begin();
            int cycleSize = (int)st.size() - startIndex;
            for(int i = startIndex; i < (int)st.size(); ++i){
                res[st[i]] = cycleSize;
            }
        }else{
            dfs(nextNode, st, inStack, edges, res);
        }
        
        if(res[node] == 0){
            res[node] = 1 + res[nextNode];
        }

        st.pop_back();
        inStack[node] = false;
    }
    
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        const int N = edges.size();
        
        vector<int> st;
        vector<bool> inStack(N, false);
        vector<int> res(N);
        for(int node = 0; node < N; ++node){
            dfs(node, st, inStack, edges, res);
        }
        
        return res;
    }
};