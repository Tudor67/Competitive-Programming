class TreeAncestor {
private:
    vector<vector<int>> p;
    
public:
    TreeAncestor(int n, vector<int>& parent) {
        const int N = n;
        const int LOG_N = floor(log2(n));
        
        p.resize(LOG_N + 1, vector<int>(N, -1));
        for(int node = 1; node < N; ++node){
            p[0][node] = parent[node];
        }
        
        for(int bit = 1; bit <= LOG_N; ++bit){
            for(int node = 1; node < N; ++node){
                int ancestor = p[bit - 1][node];
                if(ancestor >= 0){
                    p[bit][node] = p[bit - 1][ancestor];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int ancestor = node;
        int bit = 0;
        while(k > 0 && ancestor != -1){
            if(k % 2 == 1){
                ancestor = p[bit][ancestor];
            }
            k /= 2;
            bit += 1;
        }
        return ancestor;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */