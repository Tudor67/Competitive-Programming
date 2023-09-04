class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        
        vector<int> freq(N + 1);
        vector<int> C(N);
        for(int i = 0; i < N; ++i){
            freq[A[i]] += 1;
            freq[B[i]] += 1;
            C[i] = count(freq.begin(), freq.end(), 2);
        }
        
        return C;
    }
};