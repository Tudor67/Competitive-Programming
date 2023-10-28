class Solution {
private:
    pair<int, int> computeMaxPalindromeLengthAndStartIndex(string& s, int i, int j){
        const int N = s.length();
        while(0 <= i && j < N && s[i] == s[j]){
            i -= 1;
            j += 1;
        }
        return {j - i - 1, i + 1};
    }

public:
    string longestPalindrome(string s) {
        const int N = s.length();

        pair<int, int> maxLenAndStartIndex = {0, 0};
        for(int i = 0; i < N; ++i){
            maxLenAndStartIndex = max(maxLenAndStartIndex, computeMaxPalindromeLengthAndStartIndex(s, i, i));
            maxLenAndStartIndex = max(maxLenAndStartIndex, computeMaxPalindromeLengthAndStartIndex(s, i, i + 1));
        }

        return s.substr(maxLenAndStartIndex.second, maxLenAndStartIndex.first);
    }
};