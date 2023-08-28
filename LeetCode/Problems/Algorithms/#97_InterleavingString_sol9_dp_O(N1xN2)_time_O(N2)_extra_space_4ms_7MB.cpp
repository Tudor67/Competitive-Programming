class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int N1 = s1.length();
        const int N2 = s2.length();
        const int N3 = s3.length();

        if(N1 + N2 != N3){
            return false;
        }

        // At (i1)th iteration:
        //    isPossible[i1 % 2][i2] = true, if s3[i1 + i2 ..] is formed by
        //                                   interleaving s1[i1 ..] and s2[i2 ..]
        //                             false, otherwise
        vector<vector<bool>> isPossible(2, vector<bool>(N2 + 1, false));
        for(int i1 = N1; i1 >= 0; --i1){
            fill(isPossible[i1 % 2].begin(), isPossible[i1 % 2].end(), false);
            for(int i2 = N2; i2 >= 0; --i2){
                if(i1 == N1 && i2 == N2){
                    isPossible[i1 % 2][i2] = true;
                }
                if(i1 < N1 && s3[i1 + i2] == s1[i1] && isPossible[(i1 + 1) % 2][i2]){
                    isPossible[i1 % 2][i2] = true;
                }
                if(i2 < N2 && s3[i1 + i2] == s2[i2] && isPossible[i1 % 2][i2 + 1]){
                    isPossible[i1 % 2][i2] = true;
                }
            }
        }

        return isPossible[0][0];
    }
};