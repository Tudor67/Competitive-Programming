class Solution {
private:
    static const int INF = 1e9;
    
    int computeMinRotations(const int& FIXED_VALUE, const vector<int>& A, const vector<int>& B){
        const int N = A.size();
        int minRotations = 0;
        for(int i = 1; i < N; ++i){
            if(FIXED_VALUE == A[i]){
                continue;
            }else if(FIXED_VALUE == B[i]){
                minRotations += 1;
            }else{
                minRotations = INF;
                break;
            }
        }
        return minRotations;
    }
    
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int answer = min(min(computeMinRotations(A[0], A, B), 1 + computeMinRotations(A[0], B, A)),
                         min(computeMinRotations(B[0], B, A), 1 + computeMinRotations(B[0], A, B)));
        if(answer == INF){
            answer = -1;
        }
        return answer;
    }
};