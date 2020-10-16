class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size() <= 1){
            return A.size();
        }
        
        int answer = 1;
        for(int i = 0, j = 1; j < A.size(); ++j){
            if(((j == 1 || A[j - 2] < A[j - 1]) && A[j - 1] > A[j]) ||
               ((j == 1 || A[j - 2] > A[j - 1]) && A[j - 1] < A[j])){
                answer = max(j - i + 1, answer);
            }else{
                i = j - 1;
            }
        }
        
        return answer;
    }
};