class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int N = strs.size();
        const int L = strs[0].length();
        
        int res = 0;
        for(int j = 0; j < L; ++j){
            for(int i = 1; i < N; ++i){
                if(strs[i - 1][j] > strs[i][j]){
                    res += 1;
                    break;
                }
            }
        }
        
        return res;
    }
};