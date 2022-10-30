class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MAX_BIT = floor(log2(n));
        const int Q = queries.size();
        const int MODULO = 1e9 + 7;
        
        vector<int> powers;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            if((n >> bit) & 1){
                powers.push_back(1 << bit);
            }
        }
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            long long prod = 1;
            for(int j = queries[i][0]; j <= queries[i][1]; ++j){
                prod = (prod * powers[j]) % MODULO;
            }
            answer[i] = prod;
        }
        
        return answer;
    }
};