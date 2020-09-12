class DSU{
private:
    map<string, string> parent;
    map<string, int> rank;
    map<string, double> cost;
    
public:    
    pair<string, double> find(string x){
        if(parent.find(x) == parent.end()){
            parent[x] = x;
            cost[x] = 1;
        }else if(x != parent[x]){
            pair<string, double> p = find(parent[x]);
            parent[x] = p.first;
            cost[x] *= p.second;
        }
        return {parent[x], cost[x]};
    }
    
    void join(string x, string y, double x_y_cost){
        pair<string, double> x_p = find(x);
        pair<string, double> y_p = find(y);
        string x_root = x_p.first;
        double x_cost = x_p.second;
        string y_root = y_p.first;
        double y_cost = y_p.second;
        
        if(x_root != y_root){
            if(rank[x_root] <= rank[y_root]){
                parent[x_root] = y_root;
                cost[x_root] = x_y_cost * cost[y] / cost[x];
            }else{
                parent[y_root] = x_root;
                cost[y_root] = (1 / x_y_cost) * cost[x] / cost[y];
            }
            
            if(rank[x_root] == rank[y_root]){
                rank[y_root] += 1;
            }
        }
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        DSU dsu;
        set<string> valid_variables;
        for(int i = 0; i < equations.size(); ++i){
            string A = equations[i][0];
            string B = equations[i][1];
            double k = values[i];
            dsu.join(A, B, k);
            valid_variables.insert({A, B});
        }
        
        vector<double> answer(queries.size(), -1);
        for(int i = 0; i < queries.size(); ++i){
            string A = queries[i][0];
            string B = queries[i][1];
            if(valid_variables.count(A) && valid_variables.count(B)){
                pair<string, double> p_A = dsu.find(A);
                pair<string, double> p_B = dsu.find(B);
                string A_root = p_A.first;
                string B_root = p_B.first;
                double A_cost = p_A.second;
                double B_cost = p_B.second;
                if(A_root == B_root){
                    answer[i] = A_cost / B_cost;
                }
            }
        }
        
        return answer;
    }
};