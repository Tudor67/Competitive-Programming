class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> minPosOf(A, N + 1);
        vector<int> maxPosOf(A, -1);
        for(int i = 0; i < N; ++i){
            minPosOf[s[i] - 'a'] = min(minPosOf[s[i] - 'a'], i);
            maxPosOf[s[i] - 'a'] = i;
        }

        vector<bool> vis(A * A, false);
        for(int i = 1; i + 1 < N; ++i){
            for(char c = 'a'; c <= 'z'; ++c){
                if(minPosOf[c - 'a'] < i && i < maxPosOf[c - 'a']){
                    int palindromeCode = A * (c - 'a') + (s[i] - 'a');
                    vis[palindromeCode] = true;
                }
            }
        }

        return count(vis.begin(), vis.end(), true);
    }
};