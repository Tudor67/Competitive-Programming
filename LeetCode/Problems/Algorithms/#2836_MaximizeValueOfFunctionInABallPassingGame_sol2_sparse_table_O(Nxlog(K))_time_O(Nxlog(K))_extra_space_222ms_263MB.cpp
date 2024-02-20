class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        const int N = receiver.size();
        const long long B = k + 1;
        const int LOG_B = log2(B) + 1;

        vector<vector<int>> nxt(LOG_B + 1, vector<int>(N));
        vector<vector<long long>> sum(LOG_B + 1, vector<long long>(N));
        for(int i = 0; i < N; ++i){
            nxt[0][i] = receiver[i];
            sum[0][i] = i;
        }

        for(int j = 1; j <= LOG_B; ++j){
            for(int i = 0; i < N; ++i){
                nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
                sum[j][i] = sum[j - 1][i] + sum[j - 1][nxt[j - 1][i]];
            }
        }

        long long res = N - 1;
        for(int startIndex = 0; startIndex < N; ++startIndex){
            int i = startIndex;
            long long currentSum = 0;
            for(int j = 0; j <= LOG_B; ++j){
                if((B >> j) & 1){
                    currentSum += sum[j][i];
                    i = nxt[j][i];
                }
            }
            res = max(res, currentSum);
        }

        return res;
    }
};