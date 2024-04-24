class Solution {
private:
    int lengthOfMaxCommonPrefix(const string& A, const string& B){
        const int A_LEN = A.length();
        const int B_LEN = B.length();
        
        for(int i = 0; i < min(A_LEN, B_LEN); ++i){
            if(A[i] != B[i]){
                return i;
            }
        }
        
        return min(A_LEN, B_LEN);
    }
    
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int maxCommonPrefixLength = min(lengthOfMaxCommonPrefix(s1, s2),
                                        lengthOfMaxCommonPrefix(s2, s3));
        
        if(maxCommonPrefixLength == 0){
            return -1;
        }
        
        return (int)(s1.length() + s2.length() + s3.length()) - 3 * maxCommonPrefixLength;
    }
};