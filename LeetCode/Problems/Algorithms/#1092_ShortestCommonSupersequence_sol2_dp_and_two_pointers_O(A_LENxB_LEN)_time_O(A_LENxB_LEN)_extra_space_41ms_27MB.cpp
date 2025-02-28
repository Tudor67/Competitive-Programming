class Solution {
private:
    int getVal(vector<vector<int>>& a, int i, int j){
        if(0 <= i && i < (int)a.size() && 0 <= j && j < (int)a[i].size()){
            return a[i][j];
        }
        return 0;
    }

public:
    string shortestCommonSupersequence(string A, string B) {
        const int A_LEN = A.length();
        const int B_LEN = B.length();

        // dp[i][j]: length of the longest common subsequence between A[i .. ] and B[j .. ]
        vector<vector<int>> dp(A_LEN, vector<int>(B_LEN));
        for(int i = 0; i < A_LEN; ++i){
            for(int j = 0; j < B_LEN; ++j){
                if(A[i] == B[j]){
                    dp[i][j] = 1 + getVal(dp, i - 1, j - 1);
                }else{
                    dp[i][j] = max(getVal(dp, i - 1, j), getVal(dp, i, j - 1));
                }
            }
        }

        string res;
        int i = A_LEN - 1;
        int j = B_LEN - 1;
        while(i >= 0 && j >= 0){
            if(A[i] == B[j] && getVal(dp, i - 1, j - 1) + 1 == dp[i][j]){
                res += A[i];
                i -= 1;
                j -= 1;
            }else if(getVal(dp, i - 1, j) == dp[i][j]){
                res += A[i];
                i -= 1;
            }else{
                res += B[j];
                j -= 1;
            }
        }

        while(i >= 0){
            res += A[i];
            i -= 1;
        }

        while(j >= 0){
            res += B[j];
            j -= 1;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};