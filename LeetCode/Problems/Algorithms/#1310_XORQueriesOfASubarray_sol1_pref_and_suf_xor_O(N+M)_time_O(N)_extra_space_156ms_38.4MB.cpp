class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int N = arr.size();
        const int M = queries.size();
        
        vector<int> prefXOR(N, 0);
        prefXOR[0] = arr[0];
        for(int i = 1; i < N; ++i){
            prefXOR[i] = arr[i] ^ prefXOR[i - 1];
        }
        
        vector<int> sufXOR(N, 0);
        sufXOR[N - 1] = arr[N - 1];
        for(int i = N - 2; i >= 0; --i){
            sufXOR[i] = arr[i] ^ sufXOR[i + 1];
        }
        
        int arrXOR = prefXOR[N - 1];
        
        vector<int> answer(M, 0);
        for(int i = 0; i < M; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            int lXOR = (l == 0 ? 0 : prefXOR[l - 1]);
            int rXOR = (r == N - 1 ? 0 : sufXOR[r + 1]);
            int rangeXOR = arrXOR ^ lXOR ^ rXOR;
            answer[i] = rangeXOR;
        }
        
        return answer;
    }
};