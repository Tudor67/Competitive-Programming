class Solution {
private:
    bool isGreater(string& a, string& b, int maxIndex, vector<bool>& isDeleted){
        for(int i = 0; i <= maxIndex; ++i){
            if(isDeleted[i] || a[i] == b[i]){
                continue;
            }else{
                return (a[i] > b[i]);
            }
        }
        return false;
    }

public:
    int minDeletionSize(vector<string>& strs) {
        const int N = strs.size();
        const int L = strs[0].length();

        vector<bool> isDeleted(L, false);
        for(int j = 0; j < L; ++j){
            for(int i = 0; i + 1 < N; ++i){
                if(isGreater(strs[i], strs[i + 1], j, isDeleted)){
                    isDeleted[j] = true;
                    break;
                }
            }
        }

        return count(isDeleted.begin(), isDeleted.end(), true);
    }
};