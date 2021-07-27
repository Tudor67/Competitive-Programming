class Solution {
private:
    int maxSubarrayMatch(const vector<int>& A, const int& N, const vector<int>& B, const int& M, const int& B_START_IDX){
        int maxConsecutiveMatches = 0;
        int consecutiveMatches = 0;
        for(int i = 0, j = B_START_IDX; i < N && j < M; ++i, ++j){
            if(0 <= j){
                if(A[i] == B[j]){
                    consecutiveMatches += 1;
                    maxConsecutiveMatches = max(maxConsecutiveMatches, consecutiveMatches);
                }else{
                    consecutiveMatches = 0;
                }
            }
        }
        return maxConsecutiveMatches;
    }
    
public:
    int findLength(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        const int M = B.size();
        int maxLength = 0;
        for(int j = -N + 1; j < M; ++j){
            maxLength = max(maxLength, maxSubarrayMatch(A, N, B, M, j));
        }
        return maxLength;
    }
};