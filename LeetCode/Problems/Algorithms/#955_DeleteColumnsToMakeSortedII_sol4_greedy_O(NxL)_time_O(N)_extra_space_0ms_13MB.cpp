class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int N = strs.size();
        const int L = strs[0].length();

        int minDeletions = 0;
        vector<bool> isLess(N, false);

        for(int j = 0; j < L; ++j){
            bool needsDeletion = false;
            for(int i = 0; i + 1 < N; ++i){
                if(!isLess[i] && strs[i][j] > strs[i + 1][j]){
                    needsDeletion = true;
                    break;
                }
            }

            if(needsDeletion){
                minDeletions += 1;
            }else{
                for(int i = 0; i + 1 < N; ++i){
                    isLess[i] = isLess[i] || (strs[i][j] < strs[i + 1][j]);
                }
            }
        }

        return minDeletions;
    }
};