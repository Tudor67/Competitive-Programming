class Solution {
public:
    bool checkStrings(string s1, string s2) {
        const int N = s1.length();
        const int A = 26;
        const char FIRST_ELEM = 'a';

        vector<vector<int>> balance(2, vector<int>(A));
        for(int i = 0; i < N; ++i){
            balance[i % 2][s1[i] - FIRST_ELEM] += 1;
            balance[i % 2][s2[i] - FIRST_ELEM] -= 1;
        }

        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < A; ++j){
                if(balance[i][j] != 0){
                    return false;
                }
            }
        }

        return true;
    }
};