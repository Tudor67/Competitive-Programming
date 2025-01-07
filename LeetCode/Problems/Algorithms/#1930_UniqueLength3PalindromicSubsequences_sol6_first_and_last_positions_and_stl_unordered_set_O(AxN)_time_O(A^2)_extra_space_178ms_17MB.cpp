class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> firstPosOf(A, N);
        vector<int> lastPosOf(A, -1);
        for(int i = 0; i < N; ++i){
            firstPosOf[s[i] - 'a'] = min(firstPosOf[s[i] - 'a'], i);
            lastPosOf[s[i] - 'a'] = i;
        }

        unordered_set<int> palindromeCodes;
        for(int i = 1; i + 1 < N; ++i){
            for(char c = 'a'; c <= 'z'; ++c){
                if(firstPosOf[c - 'a'] < i && i < lastPosOf[c - 'a']){
                    palindromeCodes.insert((c - 'a') * A + s[i] - 'a');
                }
            }
        }

        return palindromeCodes.size();
    }
};