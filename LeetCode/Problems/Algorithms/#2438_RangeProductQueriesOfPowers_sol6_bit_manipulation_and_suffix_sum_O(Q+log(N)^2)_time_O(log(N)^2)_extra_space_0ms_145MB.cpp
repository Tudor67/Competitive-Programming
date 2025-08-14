class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int Q = queries.size();
        const int MODULO = 1'000'000'007;

        vector<int> suffSum;
        for(int bit = 0; (1 << bit) <= n; ++bit){
            if((n >> bit) & 1){
                suffSum.push_back(bit);
            }
        }

        suffSum.push_back(0);
        for(int i = (int)suffSum.size() - 2; i >= 0; --i){
            suffSum[i] += suffSum[i + 1];
        }

        vector<int> pows2(suffSum[0] + 1, 1);
        for(int i = 1; i < (int)pows2.size(); ++i){
            pows2[i] = (2 * pows2[i - 1]) % MODULO;
        }

        vector<int> answer(Q);
        for(int qIdx = 0; qIdx < Q; ++qIdx){
            int l = queries[qIdx][0];
            int r = queries[qIdx][1];
            answer[qIdx] = pows2[suffSum[l] - suffSum[r + 1]];
        }

        return answer;
    }
};