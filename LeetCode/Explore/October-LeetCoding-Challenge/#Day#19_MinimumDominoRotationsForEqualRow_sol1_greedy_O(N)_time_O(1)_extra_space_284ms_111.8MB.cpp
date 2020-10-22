class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        int answer = N;
        
        for(int swapCase = 1; swapCase >= 0; --swapCase){
            // Step 0: swap A[0] with B[0] to cover all possible cases
            swap(A[0], B[0]);
            
            // Step 1: Fix A[0] and compute the number of rotations
            bool ok = true;
            int rotations = swapCase;
            for(int i = 1; ok && i < N; ++i){
                if(A[0] == A[i]){
                    continue;
                }else if(A[0] == B[i]){
                    rotations += 1;
                }else{
                    ok = false;
                }
            }

            if(ok){
                answer = min(rotations, answer);
            }

            // Step 2: Fix B[0] and compute the number of rotations
            ok = true;
            rotations = swapCase;
            for(int i = 1; ok && i < N; ++i){
                if(B[0] == B[i]){
                    continue;
                }else if(B[0] == A[i]){
                    rotations += 1;
                }else{
                    ok = false;
                }
            }

            if(ok){
                answer = min(rotations, answer);
            }
        }
        
        // Step 3: check if the answer is valid
        if(answer == N){
            answer = -1;
        }
        
        return answer;
    }
};