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
        
        const int P = powers.size();
        vector<vector<int>> prod(P, vector<int>(P));
        for(int i = 0; i < P; ++i){
            long long currentProduct = 1;
            for(int j = i; j < P; ++j){
                currentProduct = (currentProduct * powers[j]) % MODULO;
                prod[i][j] = currentProduct;
            }
        }
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            answer[i] = prod[queries[i][0]][queries[i][1]];
        }
        
        return answer;
    }
};