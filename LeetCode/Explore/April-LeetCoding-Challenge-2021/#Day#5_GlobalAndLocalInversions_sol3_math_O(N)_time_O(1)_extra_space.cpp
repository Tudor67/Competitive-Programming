class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        const int N = A.size();
        for(int i = 0; i < N; ++i){
            if(abs(i - A[i]) > 1){
                return false;
            }
        }
        return true;
    }
};