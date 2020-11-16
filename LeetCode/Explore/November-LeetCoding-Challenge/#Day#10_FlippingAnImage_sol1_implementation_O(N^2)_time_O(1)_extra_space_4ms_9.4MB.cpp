class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> B = A;
        for(vector<int>& row: B){
            reverse(row.begin(), row.end());
            for(int& elem: row){
                elem ^= 1;
            }
        }
        return B;
    }
};