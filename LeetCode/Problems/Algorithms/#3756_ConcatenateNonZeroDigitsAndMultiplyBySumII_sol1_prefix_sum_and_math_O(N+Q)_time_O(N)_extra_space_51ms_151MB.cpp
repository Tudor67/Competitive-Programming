class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int N = s.length();
        const int Q = queries.size();
        const long long MODULO = 1'000'000'007;

        vector<long long> prefConcat(N + 1);
        vector<int> prefNonZeros(N + 1);
        vector<int> prefSum(N + 1);
        vector<long long> pow10(N + 1, 1);
        for(int i = 1; i <= N; ++i){
            int digit = s[i - 1] - '0';
            if(digit > 0){
                prefConcat[i] = (prefConcat[i - 1] * 10 + digit) % MODULO;
                prefNonZeros[i] = prefNonZeros[i - 1] + 1;
                prefSum[i] = (prefSum[i - 1] + digit) % MODULO;
            }else{
                prefConcat[i] = prefConcat[i - 1];
                prefNonZeros[i] = prefNonZeros[i - 1];
                prefSum[i] = prefSum[i - 1];
            }
            pow10[i] = pow10[i - 1] * 10 % MODULO;
        }

        vector<int> res(Q);
        for(int qIdx = 0; qIdx < Q; ++qIdx){
            int l = queries[qIdx][0] + 1;
            int r = queries[qIdx][1] + 1;

            long long nonZeros = prefNonZeros[r] - prefNonZeros[l - 1];
            long long sum = (prefSum[r] - prefSum[l - 1] + MODULO) % MODULO;
            long long concat = (prefConcat[r] - prefConcat[l - 1] * pow10[nonZeros] % MODULO + MODULO) % MODULO;

            res[qIdx] = concat * sum % MODULO;
        }

        return res;
    }
};