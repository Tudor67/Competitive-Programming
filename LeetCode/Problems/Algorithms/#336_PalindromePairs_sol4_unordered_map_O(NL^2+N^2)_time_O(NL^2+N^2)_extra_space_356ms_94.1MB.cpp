class Solution {
private:
    static bool isPalindrome(const string& WORD){
        for(int i = 0, j = (int)WORD.length() - 1; i < j; ++i, --j){
            if(WORD[i] != WORD[j]){
                return false;
            }
        }
        return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int N = words.size();
        vector<vector<int>> answer;
        
        // Case 1 (special case): Empty word
        //                        ("" + secondWord (which is palindrome))
        //                        (firstWord (which is palindrome) + "")
        // First word  Second word
        // ""            a        -> valid pair
        // ""           cc        -> valid pair
        // aba          ""        -> valid pair
        // xy           ""        -> invalid pair
        // Add only indices of palindrome words
        vector<string>::iterator it = find(words.begin(), words.end(), "");
        if(it != words.end()){
            int emptyWordIdx = it - words.begin();
            for(int i = 0; i < N; ++i){
                if(isPalindrome(words[i]) && i != emptyWordIdx){
                    answer.push_back({i, emptyWordIdx});
                    answer.push_back({emptyWordIdx, i});
                }
            }
        }
        
        // Case 2 (easy case): Second word is consumed
        //                     (firstWordPrefix + firstWordSuffix (which is palindrome) + secondWord (equal to reversed firstWordPrefix))
        // firstWord  secondWord
        // abcxyx        cba        -> valid pair
        // abcxyx         da        -> invalid pair
        // abcxyx       zzzz        -> invalid pair (ignored)
        // for each firstWord from words:
        //    - fix each prefix - suffix of the firstWord;
        //    - if the suffix is palindrome and there is a secondWord equal to reversed prefix of the firstWord
        //      then add indices (firstWordIdx, secondWordIdx);
        unordered_map<string, int> wordIdx;
        for(int i = 0; i < N; ++i){
            wordIdx[words[i]] = i;
        }
        
        for(int i = 0; i < N; ++i){
            const int L = words[i].length();
            for(int j = 0; j < L; ++j){
                string prefix = words[i].substr(0, j + 1);
                string suffix = words[i].substr(j + 1);
                string reversedPrefix(prefix.rbegin(), prefix.rend());
                if(isPalindrome(suffix) && wordIdx.count(reversedPrefix) && i != wordIdx[reversedPrefix]){
                    answer.push_back({i, wordIdx[reversedPrefix]});
                }
            }
        }
        
        // Case 3 (difficult case): First word is consumed
        //                          (firstWord + secondWordPrefix (which is palindrome) + secondWordSuffix (equal to reversed firstWord))
        // First word  Second word
        // abc            xcba         -> valid pair
        // abc            ycba         -> valid pair
        // abc           zzcba         -> valid pair
        // abc          zkzcba         -> valid pair
        // abc           rkcba         -> invalid pair
        // abc           rkkba         -> invalid pair (ignored)
        // for each firstWord from words:
        //    - search all possible secondWords with palindrome prefix and the remaining suffix equal to reversed firstWord;
        //    - add all indices (firstWordIdx, secondWordIdx);
        unordered_map<string, vector<int>> palindromeIndicesForSuffix;
        for(int i = 0; i < N; ++i){
            const int L = words[i].length();
            for(int j = 0; j < L - 1; ++j){
                string prefix = words[i].substr(0, j + 1);
                string suffix = words[i].substr(j + 1);
                if(isPalindrome(prefix)){
                    palindromeIndicesForSuffix[suffix].push_back(i);
                }
            }
        }
        
        for(int i = 0; i < N; ++i){
            const string REVERSED_PREFIX = string(words[i].rbegin(), words[i].rend());
            if(palindromeIndicesForSuffix.count(REVERSED_PREFIX)){
                vector<int>& indices = palindromeIndicesForSuffix[REVERSED_PREFIX];
                for(int wordIdx: indices){
                    if(i != wordIdx){
                        answer.push_back({i, wordIdx});
                    }
                }
            }
        }
        
        return answer;
    }
};