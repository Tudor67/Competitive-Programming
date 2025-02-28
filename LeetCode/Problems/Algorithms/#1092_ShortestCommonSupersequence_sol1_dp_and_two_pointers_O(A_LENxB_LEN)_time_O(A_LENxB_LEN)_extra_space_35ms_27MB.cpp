class Solution {
private:
    int getVal(vector<vector<int>>& a, int i, int j){
        if(0 <= i && i < (int)a.size() && 0 <= j && j < (int)a[i].size()){
            return a[i][j];
        }
        return 0;
    }

    string computeLCS(const string& A, const string& B){
        const int A_LEN = A.length();
        const int B_LEN = B.length();

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

        string lcs;
        int i = A_LEN - 1;
        int j = B_LEN - 1;
        while(i >= 0 && j >= 0){
            if(A[i] == B[j] && getVal(dp, i - 1, j - 1) + 1 == dp[i][j]){
                lcs += A[i];
                i -= 1;
                j -= 1;
            }else if(getVal(dp, i - 1, j) == dp[i][j]){
                i -= 1;
            }else{
                j -= 1;
            }
        }

        reverse(lcs.begin(), lcs.end());

        return lcs;
    }

    void consumeChars(string& s, int& i, char stopChar, string& consumedChars){
        while(i < (int)s.length() && s[i] != stopChar){
            consumedChars += s[i];
            i += 1;
        }
        i += 1;
        i = min(i, (int)s.length());
    }

public:
    string shortestCommonSupersequence(string A, string B) {
        string res;
        string lcs = computeLCS(A, B);

        int i = 0;
        int j = 0;
        for(char c: lcs){
            consumeChars(A, i, c, res);
            consumeChars(B, j, c, res);
            res += c;
        }

        consumeChars(A, i, '$', res);
        consumeChars(B, j, '$', res);

        return res;
    }
};