class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int N = A.size();

        vector<int> res(N);
        int matches = 0;
        unordered_set<int> visA;
        unordered_set<int> visB;
        
        for(int i = 0; i < N; ++i){
            visA.insert(A[i]);
            visB.insert(B[i]);
            if(visA.count(B[i])){
                matches += 1;
            }
            if(visB.count(A[i])){
                matches += 1;
            }
            if(A[i] == B[i]){
                matches -= 1;
            }
            res[i] = matches;
        }

        return res;
    }
};