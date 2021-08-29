class Solution {
private:
    bool isSubsequence(const string& A, const string& B){
        const int A_LEN = A.length();
        const int B_LEN = B.length();
        int j = 0;
        for(int i = 0; i < A_LEN && j <= B_LEN; ++i){
            while(j < B_LEN && A[i] != B[j]){
                j += 1;
            }
            j += 1;
        }
        return (j <= B_LEN);
    }
    
public:
    int findLUSlength(vector<string>& strs) {
        const int N = strs.size();
        int answer = -1;
        for(int i = 0; i < N; ++i){
            const int L = strs[i].length();
            if(answer < L){
                bool isValid = true;
                for(int j = 0; isValid && j < N; ++j){
                    if(i != j && isSubsequence(strs[i], strs[j])){
                        isValid = false;
                    }
                }
                if(isValid){
                    answer = max(answer, L);
                }
            }
        }
        return answer;
    }
};