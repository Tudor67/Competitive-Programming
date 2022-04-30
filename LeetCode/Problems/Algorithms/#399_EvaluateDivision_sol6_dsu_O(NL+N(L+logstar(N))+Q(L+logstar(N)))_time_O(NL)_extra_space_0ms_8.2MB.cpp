class DSU{
private:
    vector<double> coef;
    vector<int> rank;
    vector<int> parent;
    
public:
    DSU(const int& N){
        coef.resize(N + 1, 1.0);
        rank.resize(N + 1);
        parent.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x]){
            coef[x] *= coef[parent[x]];
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int x, int y, double val){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                coef[xRoot] = (val * coef[y]) / coef[x];
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                coef[yRoot] = coef[x] / (coef[y] * val);
                parent[yRoot] = xRoot;
            }
        }
    }
    
    double getCoef(int x){
        find(x); // update coef[x] w.r.t. the current xRoot
        return coef[x];
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        const int E = equations.size();
        const int Q = queries.size();
        
        unordered_map<string, int> idxOf;
        int maxIdx = -1;
        for(int i = 0; i < E; ++i){
            const vector<string>& EQ = equations[i];
            const string& A = EQ[0];
            const string& B = EQ[1];
            if(!idxOf.count(A)){
                idxOf[A] = ++maxIdx;
            }
            if(!idxOf.count(B)){
                idxOf[B] = ++maxIdx;
            }
        }
        
        const int N = maxIdx + 1;
        DSU dsu(N);
        for(int i = 0; i < E; ++i){
            const vector<string>& EQ = equations[i];
            const string& A = EQ[0];
            const string& B = EQ[1];
            dsu.join(idxOf[A], idxOf[B], values[i]);
        }
        
        vector<double> res(Q);
        for(int j = 0; j < Q; ++j){
            const string& A = queries[j][0];
            const string& B = queries[j][1];
            if(idxOf.count(A) && idxOf.count(B) && dsu.find(idxOf[A]) == dsu.find(idxOf[B])){
                res[j] = dsu.getCoef(idxOf[A]) / dsu.getCoef(idxOf[B]);
            }else{
                res[j] = -1;
            }
        }
        
        return res;
    }
};