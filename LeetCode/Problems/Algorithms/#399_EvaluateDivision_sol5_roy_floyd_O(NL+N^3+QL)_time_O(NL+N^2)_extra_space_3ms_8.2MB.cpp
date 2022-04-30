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
        vector<vector<double>> minCost(N, vector<double>(N, -1));
        
        for(int i = 0; i < E; ++i){
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            minCost[idxOf[A]][idxOf[B]] = values[i];
            minCost[idxOf[B]][idxOf[A]] = 1.0 / values[i];
        }
        
        for(int i = 0; i < N; ++i){
            minCost[i][i] = 1;
        }
        
        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    if(i != j && i != k && j != k && minCost[i][k] != -1 && minCost[k][j] != -1){
                        if(minCost[i][j] == -1 || minCost[i][j] > minCost[i][k] * minCost[k][j]){
                            minCost[i][j] = minCost[i][k] * minCost[k][j];
                        }
                    }
                }
            }
        }
        
        vector<double> res(Q);
        for(int j = 0; j < Q; ++j){
            const string& A = queries[j][0];
            const string& B = queries[j][1];
            if(idxOf.count(A) && idxOf.count(B)){
                res[j] = minCost[idxOf[A]][idxOf[B]];
            }else{
                res[j] = -1;
            }
        }
        
        return res;
    }
};