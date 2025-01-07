class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int N = s.length();
        const int A = 26;

        vector<vector<int>> positionsOf(A);
        for(int i = 0; i < N; ++i){
            positionsOf[s[i] - 'a'].push_back(i);
        }

        int palindromes = 0;
        for(char c1 = 'a'; c1 <= 'z'; ++c1){
            for(char c2 = 'a'; c2 <= 'z'; ++c2){
                vector<int>& p1 = positionsOf[c1 - 'a'];
                vector<int>& p2 = positionsOf[c2 - 'a'];
                
                if(p1.empty()){
                    break;
                }

                auto it = upper_bound(p2.begin(), p2.end(), p1.front());
                if(it != p2.end() && p1.front() < *it && *it < p1.back()){
                    palindromes += 1;
                }
            }
        }
        
        return palindromes;
    }
};