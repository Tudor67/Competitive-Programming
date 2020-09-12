class Solution {
private:
    double path_cost(map<string, vector<pair<string, double>>>& G, const string& A, const string& B){
        double res = -1;
        set<string> vis;
        vis.insert(A);
        queue<pair<string, double>> q;
        q.push({A, 1});
        while(!q.empty()){
            string node = q.front().first;
            double cost = q.front().second;
            q.pop();
            if(node == B){
                res = cost;
                break;
            }
            for(const pair<string, double>& P: G[node]){
                string next_node = P.first;
                double transition_cost = P.second;
                if(!vis.count(next_node)){
                    q.push({next_node, cost * transition_cost});
                    vis.insert(next_node);
                }
            }
        }
        return res;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> G;
        for(int i = 0; i < equations.size(); ++i){
            string A = equations[i][0];
            string B = equations[i][1];
            double k = values[i];
            G[A].push_back({B, k});
            G[B].push_back({A, 1 / k});
        }
        
        vector<double> answer(queries.size(), -1);
        for(int i = 0; i < queries.size(); ++i){
            string A = queries[i][0];
            string B = queries[i][1];
            if(G.count(A) && G.count(B)){
                answer[i] = path_cost(G, A, B);
            }
        }
        
        return answer;
    }
};