class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int Q = queries.size();
        const int MODULO = 1'000'000'007;

        vector<int> answer(Q);

        for(int qIdx = 0; qIdx < Q; ++qIdx){
            int l = queries[qIdx][0];
            int r = queries[qIdx][1];

            long long prod = 1;

            int oneBits = 0;
            for(int bit = 0; (1 << bit) <= n; ++bit){
                if((n >> bit) & 1){
                    oneBits += 1;
                    if(l + 1 <= oneBits && oneBits <= r + 1){
                        prod *= (1 << bit);
                        prod %= MODULO;
                    }
                }
            }

            answer[qIdx] = prod;
        }

        return answer;
    }
};