class Solution {
public:
    int arrayNesting(vector<int>& A) {
        const int N = A.size();
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            int cycleSize = 0;
            for(int j = i; A[j] >= 0; j = abs(A[j]) - 1){
                A[j] = -(A[j] + 1);
                cycleSize += 1;
            }
            answer = max(cycleSize, answer);
        }
        
        for(int i = 0; i < N; ++i){
            A[i] = abs(A[i]) - 1;
        }
        
        return answer;
    }
};