class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int N = strs.size();
        const int L = strs[0].length();
        
        // At jth iteration (after applying necessary deletions for columns 0 .. j):
        //    isStrictlySorted[i] = (strs[i][j] < strs[i + 1][j])
        vector<bool> isStrictlySorted(N - 1, false);
        
        int minDeletions = 0;
        for(int j = 0; j < L; ++j){
            int i = 0;
            while(i + 1 < N){
                if(isStrictlySorted[i] || strs[i][j] <= strs[i + 1][j]){
                    i += 1;
                }else{
                    minDeletions += 1;
                    break;
                }
            }
            
            if(i + 1 >= N){
                i = 0;
                while(i + 1 < N){
                    if(strs[i][j] < strs[i + 1][j]){
                        isStrictlySorted[i] = true;
                    }
                    i += 1;
                }
            }
        }
        
        return minDeletions;
    }
};