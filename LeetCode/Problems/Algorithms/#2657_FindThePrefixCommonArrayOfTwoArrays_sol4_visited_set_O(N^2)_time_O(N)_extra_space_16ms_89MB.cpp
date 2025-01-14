class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int N = A.size();

        vector<int> res(N);
        unordered_set<int> visA;
        
        for(int i = 0; i < N; ++i){
            visA.insert(A[i]);
            for(int j = 0; j <= i; ++j){
                if(visA.count(B[j])){
                    res[i] += 1;
                }
            }
        }

        return res;
    }
};