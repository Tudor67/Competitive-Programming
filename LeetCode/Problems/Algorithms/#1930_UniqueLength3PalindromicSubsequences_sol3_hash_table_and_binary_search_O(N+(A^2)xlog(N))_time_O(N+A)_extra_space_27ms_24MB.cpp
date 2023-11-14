class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int N = s.length();
        const int A = 26;

        vector<vector<int>> positionsOf(A);
        for(int i = 0; i < N; ++i){
            positionsOf[s[i] - 'a'].push_back(i);
        }

        int res = 0;
        for(char c1 = 'a'; c1 <= 'z'; ++c1){
            for(char c2 = 'a'; c2 <= 'z'; ++c2){
                vector<int>& v1 = positionsOf[c1 - 'a'];
                vector<int>& v2 = positionsOf[c2 - 'a'];
                
                if((int)v1.size() >= 2 && (int)v2.size() >= 1){
                    vector<int>::iterator it = upper_bound(v2.begin(), v2.end(), v1.front());
                    if(it != v2.end() && v1.front() < *it && *it < v1.back()){
                        res += 1;
                    }
                }
            }
        }

        return res;
    }
};