class Solution {
private:
    int minRotations(const int& FIXED_VALUE, const vector<int>& A, const vector<int>& B){
        const int N = A.size();
        bool ok = true;
        int rotations = 0;
        
        for(int i = 1; ok && i < N; ++i){
            if(FIXED_VALUE == A[i]){
                continue;
            }else if(FIXED_VALUE == B[i]){
                rotations += 1;
            }else{
                ok = false;
            }
        }
        
        if(ok){
            return rotations;
        }
        
        return N;
    }
    
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        int answer = min({minRotations(A[0], A, B), 1 + minRotations(A[0], B, A),
                          minRotations(B[0], B, A), 1 + minRotations(B[0], A, B)});
        
        if(answer == N){
            answer = -1;
        }
        
        return answer;
    }
};