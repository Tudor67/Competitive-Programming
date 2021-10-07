class Solution {
private:
    bool isPalindrome(const string& S, const int& POS1, const int& POS2){
        for(int i = POS1, j = POS2; i < j; ++i, --j){
            if(S[i] != S[j]){
                return false;
            }
        }
        return true;
    }
    
    bool isPossiblePalindrome(const string& A, const string& B){
        const int N = A.length();
        int pos1;
        int pos2;
        for(pos1 = 0, pos2 = N - 1; pos1 < pos2; ++pos1, --pos2){
            if(A[pos1] != B[pos2]){
                break;
            }
        }
        return isPalindrome(A, pos1, pos2) || isPalindrome(B, pos1, pos2);
    }
    
public:
    bool checkPalindromeFormation(string a, string b) {
        return isPossiblePalindrome(a, b) || isPossiblePalindrome(b, a);
    }
};