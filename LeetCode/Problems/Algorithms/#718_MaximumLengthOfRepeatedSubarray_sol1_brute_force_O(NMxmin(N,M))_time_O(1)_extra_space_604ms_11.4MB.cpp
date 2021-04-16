class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        const int M = B.size();
        
        int answer = 0;
        for(int i = 0; i + answer < N; ++i){
            for(int j = 0; j + answer < M; ++j){
                int k = 0;
                while(i + k < N && j + k < M && A[i + k] == B[j + k]){
                    k += 1;
                }
                answer = max(k, answer);
            }
        }
        
        return answer;
    }
};