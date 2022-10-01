class Solution {
private:
    void bfs(int srcNode, int cc, vector<int>& ccOf, const vector<vector<int>>& G){
        queue<int> q;
        if(ccOf[srcNode] == 0){
            q.push(srcNode);
            ccOf[srcNode] = cc;
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: G[node]){
                if(ccOf[nextNode] == 0){
                    ccOf[nextNode] = cc;
                    q.push(nextNode);
                }
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
                bfs(node, cc, ccOf, G);
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