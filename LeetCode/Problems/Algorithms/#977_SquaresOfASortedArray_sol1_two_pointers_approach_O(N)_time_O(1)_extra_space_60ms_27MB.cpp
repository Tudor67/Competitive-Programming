class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        const int N = A.size();
        vector<int> answer;
        
        int l = N - 2;
        int r = N - 1;
        for(int i = 0; i < N; ++i){
            if(A[i] >= 0){
                l = i - 1;
                r = i;
                break;
            }
        }
        
        while(l >= 0 && r <= N - 1){
            if(A[l] * A[l] >= A[r] * A[r]){
                answer.push_back(A[r] * A[r]);
                r += 1;
            }else{
                answer.push_back(A[l] * A[l]);
                l -= 1;
            }
        }
        
        for(; l >= 0; --l){
            answer.push_back(A[l] * A[l]);
        }
        
        for(; r <= N - 1; ++r){
            answer.push_back(A[r] * A[r]);
        }
        
        return answer;
    }
};