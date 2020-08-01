class Solution {
private:
    vector<vector<int>> AUX;
    
    void mult(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C){
        for(int i = 0; i < AUX.size(); ++i){
            for(int j = 0; j < AUX[0].size(); ++j){
                AUX[i][j] = 0;
                for(int k = 0; k < AUX[0].size(); ++k){
                    AUX[i][j] += A[i][k] * B[j][k];
                }
            }
        }
        C = AUX;
    }
    
    void binary_exponentiation(vector<vector<int>>& A, int n, vector<vector<int>>& P){
        AUX = {{0, 0}, {0, 0}};
        P = {{1, 0}, {0, 1}};
        while(n > 0){
            if(n & 1){
                mult(A, P, P);
            }
            n /= 2;
            if(n > 0){
                mult(A, A, A);
            }
        }
    }
    
public:
    int climbStairs(int n) {
        vector<vector<int>> A = {{0, 1}, {1, 1}};
        vector<vector<int>> P;
        binary_exponentiation(A, n, P);
        return P[1][1];
    }
};