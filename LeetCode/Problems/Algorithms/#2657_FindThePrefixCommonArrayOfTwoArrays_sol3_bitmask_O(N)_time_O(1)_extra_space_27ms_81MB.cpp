class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int N = A.size();

        vector<int> C(N);
        int intersectionSize = 0;
        long long visMask = 0;

        for(int i = 0; i < N; ++i){
            if((visMask >> A[i]) & 1){
                intersectionSize += 1;
            }
            visMask |= (1LL << A[i]);

            if((visMask >> B[i]) & 1){
                intersectionSize += 1;
            }
            visMask |= (1LL << B[i]);

            C[i] = intersectionSize;
        }

        return C;
    }
};