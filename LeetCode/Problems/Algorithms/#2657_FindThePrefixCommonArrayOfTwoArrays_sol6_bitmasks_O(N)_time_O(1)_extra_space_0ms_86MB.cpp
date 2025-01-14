class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int N = A.size();

        vector<int> res(N);
        long long visMaskA = 0;
        long long visMaskB = 0;
        
        for(int i = 0; i < N; ++i){
            visMaskA |= (1LL << A[i]);
            visMaskB |= (1LL << B[i]);
            res[i] = __builtin_popcountll(visMaskA & visMaskB);
        }

        return res;
    }
};