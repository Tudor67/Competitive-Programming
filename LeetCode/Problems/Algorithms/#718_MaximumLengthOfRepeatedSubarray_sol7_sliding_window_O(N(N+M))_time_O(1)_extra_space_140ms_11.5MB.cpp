class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        const int M = B.size();
        
        int answer = 0;
        for(int shift = -N + 1; shift < M; ++shift){
            int consecutiveMatches = 0;
            for(int i = 0; i < N; ++i){
                if(0 <= i + shift && i + shift < M){
                    if(A[i] == B[i + shift]){
                        consecutiveMatches += 1;
                        answer = max(consecutiveMatches, answer);
                    }else{
                        consecutiveMatches = 0;
                    }
                }
            }
        }
        
        return answer;
    }
};