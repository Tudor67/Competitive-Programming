class Solution {
private:
    const int MODULO = 1e9 + 7;

    int solve(int n, int k, unordered_map<int, int>& memo){
        if(n == 1 || k == 1){
            return 1;
        }

        int state = (n << 13) | k;
        if(memo.count(state)){
            return memo[state];
        }

        int res = 0;
        for(int d = 1; d * d <= k; ++d){
            if(k % d == 0){
                res = (res + solve(n - 1, k / d, memo)) % MODULO;
                if(d != k / d){
                    res = (res + solve(n - 1, d, memo)) % MODULO;
                }
            }
        }

        memo[state] = res;
        return res;
    }

public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        const int Q = queries.size();

        vector<int> answer(Q);
        unordered_map<int, int> memo;
        for(int i = 0; i < Q; ++i){
            const int N = queries[i][0];
            const int K = queries[i][1];
            answer[i] = solve(N, K, memo);
        }

        return answer;
    }
};