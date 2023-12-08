class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        const long long Q = queries.size();
        
        long long res = 0;
        unordered_set<int> visRows;
        unordered_set<int> visCols;
        
        for(int i = Q - 1; i >= 0; --i){
            int opType = queries[i][0];
            int idx = queries[i][1];
            long long val = queries[i][2];
            
            if(opType == 0){
                if(!visRows.count(idx)){
                    res += val * (n - (long long)visCols.size());
                    visRows.insert(idx);
                }
            }else{
                if(!visCols.count(idx)){
                    res += val * (n - (long long)visRows.size());
                    visCols.insert(idx);
                }
            }
        }
        
        return res;
    }
};