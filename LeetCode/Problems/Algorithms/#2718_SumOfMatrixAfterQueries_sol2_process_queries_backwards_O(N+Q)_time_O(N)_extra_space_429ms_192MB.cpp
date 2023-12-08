class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        const long long Q = queries.size();
        
        long long res = 0;
        long long visRowsCount = 0;
        long long visColsCount = 0;
        vector<bool> visRows(n, false);
        vector<bool> visCols(n, false);
        
        for(int i = Q - 1; i >= 0; --i){
            int opType = queries[i][0];
            int idx = queries[i][1];
            long long val = queries[i][2];
            
            if(opType == 0){
                if(!visRows[idx]){
                    res += val * (n - visColsCount);
                    visRows[idx] = true;
                    visRowsCount += 1;
                }
            }else{
                if(!visCols[idx]){
                    res += val * (n - visRowsCount);
                    visCols[idx] = true;
                    visColsCount += 1;
                }
            }
        }
        
        return res;
    }
};