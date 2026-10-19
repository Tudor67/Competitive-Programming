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

    string distributeCharsAndMakePalindrome(const string& FIXED_PREFIX, vector<int> remFreq, const int N){
        string palindrome(N, '$');
        copy(FIXED_PREFIX.begin(), FIXED_PREFIX.end(), palindrome.begin());
        copy(FIXED_PREFIX.begin(), FIXED_PREFIX.end(), palindrome.rbegin());

        int l = FIXED_PREFIX.length();
        int r = N - 1 - l;
        for(char c = FIRST_CHAR; c <= LAST_CHAR; ++c){
            int cIndex = c - FIRST_CHAR;
            while(remFreq[cIndex] >= 1){
                if(remFreq[cIndex] % 2 == 1){
                    palindrome[N / 2] = c;
                    remFreq[cIndex] -= 1;
                }else{
                    palindrome[l] = c;
                    palindrome[r] = c;
                    l += 1;
                    r -= 1;
                    remFreq[cIndex] -= 2;
                }
            }
        }

        return palindrome;
    }

    bool isPossibleToMakePalindrome(const vector<int>& FREQ){
        int len = 0;
        int oddFreqCount = 0;
        for(int f: FREQ){
            len += f;
            oddFreqCount += (f % 2);
        }
        return (oddFreqCount == len % 2);
    }

    int computeFreqNeedForPalindrome(int index, int len){
        if(len % 2 == 1 && index == len / 2){
            return 1;
        }
        return 2;
    }

    void updateRemLenRemOddFreqCountRemFreq(int& remLen, int& remOddFreqCount, vector<int>& remFreq,
                                            int charIndex, int charNeed){
        remLen -= remFreq[charIndex];
        remOddFreqCount -= (remFreq[charIndex] % 2);
        remFreq[charIndex] += charNeed;
        remLen += remFreq[charIndex];
        remOddFreqCount += (remFreq[charIndex] % 2);
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

        if(!isPossibleToMakePalindrome(sFreq)){
            return "";
        }

        // Case 1: mirror the first half of the target
        string palindrome = makePalindromeFromFirstHalf(target);
        if(palindrome > target && isPermutation(palindrome, s)){
            return palindrome;
        }

        // Case 2: increase and mirror the first half of the target
        int startIndex = -1;
        vector<int> remFreq = sFreq;
        for(int i = 0; i < (N + 1) / 2; ++i){
            int charIndex = target[i] - FIRST_CHAR;
            int charNeed = computeFreqNeedForPalindrome(i, N);
            remFreq[charIndex] -= charNeed;
            startIndex = i;
            if(remFreq[charIndex] < 0){
                break;
            }
        }

        int remLen = 0;
        int remOddFreqCount = 0;
        for(int f: remFreq){
            remLen += f;
            remOddFreqCount += (f % 2);
        }

        for(int i = startIndex; i >= 0; --i){
            int charIndex = target[i] - FIRST_CHAR;
            int charNeed = computeFreqNeedForPalindrome(i, N);

            updateRemLenRemOddFreqCountRemFreq(remLen, remOddFreqCount, remFreq, charIndex, charNeed);

            for(char newChar = target[i] + 1; newChar <= LAST_CHAR; ++newChar){
                int newCharIndex = newChar - FIRST_CHAR;
                int newCharNeed = computeFreqNeedForPalindrome(i, N);
                if(remFreq[newCharIndex] < newCharNeed){
                    continue;
                }

                updateRemLenRemOddFreqCountRemFreq(remLen, remOddFreqCount, remFreq, newCharIndex, -newCharNeed);

                if(remOddFreqCount == remLen % 2){
                    string fixedPrefix = target.substr(0, i) + newChar;
                    return distributeCharsAndMakePalindrome(fixedPrefix, remFreq, N);
                }

                updateRemLenRemOddFreqCountRemFreq(remLen, remOddFreqCount, remFreq, newCharIndex, newCharNeed);
            }
        }

        return "";
    }
};