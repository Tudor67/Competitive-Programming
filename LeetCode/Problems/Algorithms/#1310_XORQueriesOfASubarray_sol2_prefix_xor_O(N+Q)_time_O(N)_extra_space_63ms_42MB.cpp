class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int N = arr.size();
        const int Q = queries.size();

        vector<int> prefXOR(N);
        prefXOR[0] = arr[0];
        for(int i = 1; i < N; ++i){
            prefXOR[i] = prefXOR[i - 1] ^ arr[i];
        }

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l == 0){
                res[i] = prefXOR[r];
            }else{
                res[i] = prefXOR[r] ^ prefXOR[l - 1];
            }
        }

        return res;
    }
};