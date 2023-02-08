class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        const int Q = queries.size();
        const int MODULO = 1e9 + 7;

        int maxN = 0;
        int maxK = 0;
        for(int i = 0; i < Q; ++i){
            maxN = max(maxN, queries[i][0]);
            maxK = max(maxK, queries[i][1]);
        }

        vector<int> answer(Q);
        vector<tuple<int, int, int>> v(Q);
        for(int i = 0; i < Q; ++i){
            v[i] = {queries[i][0], queries[i][1], i};
        }

        sort(v.begin(), v.end());

        // At iteration number n:
        //    dp[n % 2][k]: number of different ways we can write k as product of n positive numbers
        vector<vector<long long>> dp(2, vector<long long>(maxK + 1));
        for(int k = 1; k <= maxK; ++k){
            dp[1][k] = 1;
        }

        int index = 0;
        for(int i = 1; i <= maxN - 1; ++i){
            fill(dp[(i + 1) % 2].begin(), dp[(i + 1) % 2].end(), 0);
            dp[(i + 1) % 2][1] = 1;

            for(int k = 1; k <= maxK; ++k){
                for(int f = 1; k * f <= maxK; ++f){
                    if(k * f != 1){
                        dp[(i + 1) % 2][k * f] += dp[i % 2][k];
                        dp[(i + 1) % 2][k * f] %= MODULO;
                    }
                }
            }

            while(index < Q && get<0>(v[index]) <= i + 1){
                const int N = get<0>(v[index]);
                const int K = get<1>(v[index]);
                int queryIndex = get<2>(v[index]);
                if(N == i){
                    answer[queryIndex] = dp[i % 2][K];
                }else if(N == i + 1){
                    answer[queryIndex] = dp[(i + 1) % 2][K];
                }
                index += 1;
            }
        }

        return answer;
    }
};