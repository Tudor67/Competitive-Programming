class Solution {
private:
    bool solve(const string& S1, int pos1, const string& S2, int pos2, const string& S3, int pos3){
        if(pos1 + pos2 + 1 != pos3){
            return false;
        }
        if(pos1 == -1 && pos2 == -1){
            return (pos3 == -1);
        }
        if(pos1 == -1){
            return (S2.substr(0, pos2 + 1) == S3.substr(0, pos3 + 1));
        }
        if(pos2 == -1){
            return (S1.substr(0, pos1 + 1) == S3.substr(0, pos3 + 1));
        }
        return (S1[pos1] == S3[pos3] && solve(S1, pos1 - 1, S2, pos2, S3, pos3 - 1))
                ||
               (S2[pos2] == S3[pos3] && solve(S1, pos1, S2, pos2 - 1, S3, pos3 - 1));
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int N1 = s1.length();
        const int N2 = s2.length();
        const int N3 = s3.length();
        return solve(s1, N1 - 1, s2, N2 - 1, s3, N3 - 1);
    }
};