class Solution {
private:
    void generatePalindromes(int level, string& st, const int& TARGET_LENGTH, vector<long long>& palindromes){
        if(2 * level >= TARGET_LENGTH){
            string palindromeStr(TARGET_LENGTH, '#');
            for(int i = 0, j = TARGET_LENGTH - 1; i <= j; ++i, --j){
                palindromeStr[i] = st[i];
                palindromeStr[j] = st[i];
            }
            palindromes.push_back(stoll(palindromeStr));
        }else{
            for(char c = '0' + (level == 0); c <= '9'; ++c){
                st.push_back(c);
                generatePalindromes(level + 1, st, TARGET_LENGTH, palindromes);
                st.pop_back();
            }
        }
    }
    
    bool isPalindrome(long long num){
        long long numRev = 0;
        for(long long x = num; x != 0; x /= 10){
            numRev = 10 * numRev + (x % 10);
        }
        return (num == numRev);
    }
    
public:
    int superpalindromesInRange(string leftStr, string rightStr) {
        string st;
        vector<long long> palindromes;
        for(int len = 1; len <= 9; ++len){
            generatePalindromes(0, st, len, palindromes);
        }
        
        int answer = 0;
        long long left = stoll(leftStr);
        long long right = stoll(rightStr);
        for(const long long& PALINDROME: palindromes){
            long long superPalindromeCandidate = PALINDROME * PALINDROME;
            if(left <= superPalindromeCandidate && superPalindromeCandidate <= right){
                answer += isPalindrome(superPalindromeCandidate);
            }
        }
        
        return answer;
    }
};