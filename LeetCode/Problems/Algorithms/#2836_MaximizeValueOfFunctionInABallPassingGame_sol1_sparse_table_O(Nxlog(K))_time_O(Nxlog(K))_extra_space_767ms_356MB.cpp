class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        const int N = receiver.size();
        const long long B = k + 1;
        const int LOG_B = log2(B) + 1;

        vector<vector<int>> nxt(N, vector<int>(LOG_B + 1));
        vector<vector<long long>> sum(N, vector<long long>(LOG_B + 1));
        for(int i = 0; i < N; ++i){
            nxt[i][0] = receiver[i];
            sum[i][0] = i;
        }

        for(int j = 1; j <= LOG_B; ++j){
            for(int i = 0; i < N; ++i){
                nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
                sum[i][j] = sum[i][j - 1] + sum[nxt[i][j - 1]][j - 1];
            }
        }

        long long res = N - 1;
        for(int startIndex = 0; startIndex < N; ++startIndex){
            int i = startIndex;
            long long currentSum = 0;
            for(int j = 0; j <= LOG_B; ++j){
                if((B >> j) & 1){
                    currentSum += sum[i][j];
                    i = nxt[i][j];
                }
            }
            res = max(res, currentSum);
        }

        return res;
    }
};