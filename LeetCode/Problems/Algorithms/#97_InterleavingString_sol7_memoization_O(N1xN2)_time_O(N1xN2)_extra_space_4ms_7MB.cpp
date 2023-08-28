class Solution {
private:
    bool isPossible(int i1, int i2, string& s1, string& s2, string& s3, vector<vector<int>>& memo){
        const int N1 = s1.length();
        const int N2 = s2.length();

        if(i1 >= N1 && i2 >= N2){
            return true;
        }

        if(memo[i1][i2] < 0){
            memo[i1][i2] = (i1 < N1 && s1[i1] == s3[i1 + i2] && isPossible(i1 + 1, i2, s1, s2, s3, memo)) ||
                           (i2 < N2 && s2[i2] == s3[i1 + i2] && isPossible(i1, i2 + 1, s1, s2, s3, memo));
        }

        return memo[i1][i2];
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        const int N1 = s1.length();
        const int N2 = s2.length();
        const int N3 = s3.length();

        if(N1 + N2 != N3){
            return false;
        }

        vector<vector<int>> memo(N1 + 1, vector<int>(N2 + 1, -1));
        return isPossible(0, 0, s1, s2, s3, memo);
    }
};