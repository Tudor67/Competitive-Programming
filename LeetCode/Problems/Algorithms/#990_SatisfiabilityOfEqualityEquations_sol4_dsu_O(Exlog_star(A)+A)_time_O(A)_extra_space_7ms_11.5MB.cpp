class DSU{
private:
    vector<int> rank;
    vector<int> parent;
    
public:
    DSU(const int& N){
        rank.resize(N);
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        const int A = 26;
        
        DSU dsu(A);
        for(const string& EQ: equations){
            int a = EQ.front() - 'a';
            int b = EQ.back() - 'a';
            if(EQ[1] == '='){
                dsu.join(a, b);
            }
        }
        
        for(const string& EQ: equations){
            int a = EQ.front() - 'a';
            int b = EQ.back() - 'a';
            if(EQ[1] == '!' && dsu.find(a) == dsu.find(b)){
                return false;
            }
        }
        
        return true;
    }
};