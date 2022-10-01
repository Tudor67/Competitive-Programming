class Solution {
private:
    void dfs(int node, int cc, vector<int>& ccOf, const vector<vector<int>>& G){
        if(ccOf[node] == 0){
            ccOf[node] = cc;
            for(int nextNode: G[node]){
                dfs(nextNode, cc, ccOf, G);
            }
        }
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        const int A = 26;
        
        vector<vector<int>> G(A);
        for(const string& EQ: equations){
            int a = EQ.front() - 'a';
            int b = EQ.back() - 'a';
            if(EQ[1] == '='){
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
        
        int cc = 0;
        vector<int> ccOf(A);
        for(int node = 0; node < A; ++node){
            if(ccOf[node] == 0){
                cc += 1;
                dfs(node, cc, ccOf, G);
            }
        }
        
        for(const string& EQ: equations){
            int a = EQ.front() - 'a';
            int b = EQ.back() - 'a';
            if(EQ[1] == '!' && ccOf[a] == ccOf[b]){
                return false;
            }
        }
        
        return true;
    }
};