class Solution {
public:
    string smallestPalindrome(string s) {
        const int N = s.length();

        sort(s.begin(), s.begin() + N / 2);

        for(int i = 0, j = N - 1; i < j; ++i, --j){
            s[j] = s[i];
        }

        return s;
    }
};