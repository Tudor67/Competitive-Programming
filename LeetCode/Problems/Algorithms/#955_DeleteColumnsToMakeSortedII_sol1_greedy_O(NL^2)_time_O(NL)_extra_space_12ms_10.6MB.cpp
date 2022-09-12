class Solution {
private:
    int findBadPos(const string& A, const string& B){
        const int L = A.length();
        for(int i = 0; i < L; ++i){
            if(A[i] > B[i]){
                return i;
            }
        }
        return -1;
    }
    
public:
    int minDeletionSize(vector<string>& initialStrs) {
        const int N = initialStrs.size();
        const int L = initialStrs[0].length();
        const int SPECIAL_CHAR = '*';
        
        vector<string> strs = initialStrs;
        
        int badPos = 0;
        while(badPos >= 0){
            badPos = -1;
            for(int i = 0; i + 1 < N; ++i){
                if(strs[i] > strs[i + 1]){
                    badPos = findBadPos(strs[i], strs[i + 1]);
                    break;
                }
            }
            if(badPos >= 0){
                for(int i = 0; i < N; ++i){
                    strs[i][badPos] = SPECIAL_CHAR;
                }
            }
        }
        
        int minDeletions = count(strs[0].begin(), strs[0].end(), SPECIAL_CHAR);
        
        return minDeletions;
    }
};