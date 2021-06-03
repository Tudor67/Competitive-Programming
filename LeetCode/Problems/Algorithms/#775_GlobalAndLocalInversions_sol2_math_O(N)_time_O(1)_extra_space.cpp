class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for(int i = 0; i < (int)A.size(); ++i){
            if(abs(A[i] - i) > 1){
                return false;
            }
        }
        return true;
    }
};