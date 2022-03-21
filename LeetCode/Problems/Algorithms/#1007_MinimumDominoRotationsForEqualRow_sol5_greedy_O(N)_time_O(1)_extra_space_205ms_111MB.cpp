class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        
        vector<int> countA(7);
        vector<int> countB(7);
        vector<int> countIntersection(7);
        for(int i = 0; i < N; ++i){
            countA[A[i]] += 1;
            countB[B[i]] += 1;
            if(A[i] == B[i]){
                countIntersection[A[i]] += 1;
            }
        }
        
        for(int val = 1; val <= 6; ++val){
            if(countA[val] + countB[val] - countIntersection[val] == N){
                return N - max(countA[val], countB[val]);
            }
        }
        
        return -1;
    }
};