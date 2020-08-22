class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        const int N = A.size();
        int i = 0;
        int j = N - 1;
        while(i < j){
            if(A[i] % 2 == 0 && A[j] % 2 == 0){
                i += 1;
            }else if(A[i] % 2 == 0 && A[j] % 2 == 1){
                i += 1;
                j -= 1;
            }else if(A[i] % 2 == 1 && A[j] % 2 == 0){
                swap(A[i], A[j]);
                i += 1;
                j -= 1;
            }else if(A[i] % 2 == 1 && A[j] % 2 == 1){
                j -= 1;
            }
        }
        return A;
    }
};