class Solution {
private:
    void generatePalindromes(int level, string& st, const int& TARGET_LENGTH, vector<string>& palindromesStr){
        if(2 * level >= TARGET_LENGTH){
            string palindromeStr(TARGET_LENGTH, '#');
            for(int i = 0, j = TARGET_LENGTH - 1; i <= j; ++i, --j){
                palindromeStr[i] = st[i];
                palindromeStr[j] = st[i];
            }
            palindromesStr.push_back(palindromeStr);
        }else{
            for(char c = '0' + (level == 0); c <= '9'; ++c){
                st.push_back(c);
                generatePalindromes(level + 1, st, TARGET_LENGTH, palindromesStr);
                st.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& S){
        for(int i = 0, j = (int)S.length() - 1; i < j; ++i, --j){
            if(S[i] != S[j]){
                return false;
            }
        }
        return true;
    }
    
public:
    int superpalindromesInRange(string leftStr, string rightStr) {
        string st;
        vector<string> palindromesStr;
        for(int len = 1; len <= 9; ++len){
            generatePalindromes(0, st, len, palindromesStr);
        }
        
        int answer = 0;
        long long left = stoll(leftStr);
        long long right = stoll(rightStr);
        for(const string& PALINDROME_STR: palindromesStr){
            long long palindrome = stoll(PALINDROME_STR);
            long long superPalindromeCandidate = palindrome * palindrome;
            if(left <= superPalindromeCandidate && superPalindromeCandidate <= right){
                answer += isPalindrome(to_string(superPalindromeCandidate));
            }
        }
        
        return answer;
    }