class Solution {
private:
    bool isSubsequence(const string& A, const int& MASK, const string& B){
        const int A_LEN = A.length();
        const int B_LEN = B.length();
        int j = 0;
        for(int i = 0; i < A_LEN && j <= B_LEN; ++i){
            if((MASK >> i) & 1){
                while(j < B_LEN && A[i] != B[j]){
                    j += 1;
                }
                j += 1;
            }
        }
        return (j <= B_LEN);
    }
    
public:
    int findLUSlength(vector<string>& strs) {
        const int N = strs.size();
        int answer = -1;
        for(int i = 0; i < N; ++i){
            const int L = strs[i].length();
            const int FULL_MASK = (1 << L) - 1;
            if(L <= answer){
                continue;
            }
            for(int mask = 1; mask <= FULL_MASK; ++mask){
                if(__builtin_popcount((unsigned int)mask) <= answer){
                    continue;
                }
                bool isValid = true;
                for(int j = 0; isValid && j < N; ++j){
                    if(i != j && isSubsequence(strs[i], mask, strs[j])){
                        isValid = false;
                    }
                }
                if(isValid){
                    answer = max(answer, __builtin_popcount((unsigned int)mask));
                }
            }
        }
        return answer;
    }
};