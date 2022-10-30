class Solution {
private:
    long long fastPow(long long a, long long n, const long long& MODULO){
        long long res = 1;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n >>= 1;
        }
        return res;
    }
    
    long long modInverse(long long a, const long long& MODULO){
        return fastPow(a, MODULO - 2, MODULO);
    }
    
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MAX_BIT = floor(log2(n));
        const int Q = queries.size();
        const long long MODULO = 1e9 + 7;
        
        vector<int> powers;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            if((n >> bit) & 1){
                powers.push_back(1 << bit);
            }
        }
        
        const int P = powers.size();
        vector<long long> prefProd(P);
        vector<long long> prefProdModInverse(P);
        prefProd[0] = powers[0];
        prefProdModInverse[0] = modInverse(prefProd[0], MODULO);
        for(int i = 1; i < P; ++i){
            prefProd[i] = (prefProd[i - 1] * powers[i]) % MODULO;
            prefProdModInverse[i] = modInverse(prefProd[i], MODULO);
        }
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            const int L = queries[i][0];
            const int R = queries[i][1];
            if(L == 0){
                answer[i] = prefProd[R];
            }else{
                answer[i] = (prefProd[R] * prefProdModInverse[L - 1]) % MODULO;
            }
        }
        
        return answer;
    }
};