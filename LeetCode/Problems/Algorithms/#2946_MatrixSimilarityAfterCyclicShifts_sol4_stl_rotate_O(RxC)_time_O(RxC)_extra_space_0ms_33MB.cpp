class Solution {
public:
    bool areSimilar(vector<vector<int>>& originalMat, int k) {
        const int ROWS = originalMat.size();
        const int COLS = originalMat[0].size();

        k %= COLS;

        vector<vector<int>> currMat = originalMat;
        for(int row = 0; row < ROWS; ++row){
            if(row % 2 == 0){
                rotate(currMat[row].begin(), currMat[row].begin() + k, currMat[row].end());
            }else{
                rotate(currMat[row].begin(), currMat[row].begin() + (COLS - k) % COLS, currMat[row].end());
            }
        }

        return (currMat == originalMat);
    }
};