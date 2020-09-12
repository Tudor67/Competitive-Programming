class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N){
        rank.resize(N + 1, 0);
        parent.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int x, int y){
        int x_root = find(x);
        int y_root = find(y);
        if(x_root != y_root){
            if(rank[x_root] <= rank[y_root]){
                parent[x_root] = y_root;
            }else{
                parent[y_root] = x_root;
            }
            if(rank[x_root] == rank[y_root]){
                rank[y_root] += 1;
            }
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        const int MAX_VARIABLE = 'z';
        DSU dsu(MAX_VARIABLE);
        for(const string& EQUATION: equations){
            if(EQUATION[1] == '='){
                dsu.join(EQUATION.front(), EQUATION.back());
            }
        }
        
        bool is_valid = true;
        for(const string& EQUATION: equations){
            if(EQUATION[1] == '!'){
                if(dsu.find(EQUATION.front()) == dsu.find(EQUATION.back())){
                    is_valid = false;
                    break;
                }
            }
        }
        
        return is_valid;
    }
};