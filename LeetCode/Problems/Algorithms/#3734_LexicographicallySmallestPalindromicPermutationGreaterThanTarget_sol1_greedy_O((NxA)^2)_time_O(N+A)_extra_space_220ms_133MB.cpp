class Solution {
private:
    const char FIRST_CHAR = 'a';
    const char LAST_CHAR  = 'z';
    const int ALPHABET_SIZE = LAST_CHAR - FIRST_CHAR + 1;

    string makePalindromeFromFirstHalf(const string& S){
        const int N = S.length();
        
        string palindrome = S;
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            palindrome[j] = palindrome[i];
        }

        return palindrome;
    }

    string makePalindromeOfLengthN(const string& FIXED_PREFIX, const int N, const vector<int>& FREQ){
        string palindrome(N, '$');
        vector<int> currFreq = FREQ;

        for(int i = 0, j = N - 1; i < (int)FIXED_PREFIX.length() && i <= j; ++i, --j){
            char c = FIXED_PREFIX[i];
            int cIndex = c - FIRST_CHAR;
            int cNeed = (i == j ? 1 : 2);
            palindrome[i] = c;
            palindrome[j] = c;
            currFreq[cIndex] -= cNeed;
            if(currFreq[cIndex] < 0){
                return "";
            }
        }

        for(int i = (int)FIXED_PREFIX.length(), j = N - 1 - i; i <= j; ++i, --j){
            int cNeed = (i == j ? 1 : 2);
            char c = FIRST_CHAR;
            for(char cCandidate = FIRST_CHAR; cCandidate <= LAST_CHAR; ++cCandidate){
                if(currFreq[cCandidate - FIRST_CHAR] >= cNeed){
                    c = cCandidate;
                    break;
                }
            }

            int cIndex = c - FIRST_CHAR;
            palindrome[i] = c;
            palindrome[j] = c;
            currFreq[cIndex] -= cNeed;
            if(currFreq[cIndex] < 0){
                return "";
            }
        }

        return palindrome;
    }

    bool isPermutation(const string& A, const string& B){
        if(A.length() != B.length()){
            return false;
        }

        const int N = A.length();
        vector<int> balance(ALPHABET_SIZE);
        for(int i = 0; i < N; ++i){
            balance[A[i] - FIRST_CHAR] += 1;
            balance[B[i] - FIRST_CHAR] -= 1;
        }

        for(int b: balance){
            if(b != 0){
                return false;
            }
        }

        return true;
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        const int N = s.length();

        // Check if s can be rearranged into a palindrome
        vector<int> sFreq(ALPHABET_SIZE);
        for(char c: s){
            sFreq[c - FIRST_CHAR] += 1;
        }

        int oddFreqCount = 0;
        for(int f: sFreq){
            oddFreqCount += (f % 2);
        }

        if(N % 2 != oddFreqCount){
            return "";
        }

        // Case 1: mirror the first half of the target
        string palindrome = makePalindromeFromFirstHalf(target);
        if(palindrome > target && isPermutation(palindrome, s)){
            return palindrome;
        }

        // Case 2: increase and mirror the first half of the target
        for(int i = (N + 1) / 2 - 1; i >= 0; --i){
            for(char newChar = target[i] + 1; newChar <= LAST_CHAR; ++newChar){
                string fixedPrefix = target.substr(0, i) + newChar;
                string palindrome = makePalindromeOfLengthN(fixedPrefix, N, sFreq);
                if(!palindrome.empty()){
                    return palindrome;
                }
            }
        }

        return "";
    }
};