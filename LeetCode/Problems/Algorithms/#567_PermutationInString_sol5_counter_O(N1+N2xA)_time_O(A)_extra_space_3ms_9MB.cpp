class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int N1 = s1.length();
        const int N2 = s2.length();
        const int A = 26;

        vector<int> balance(A);
        for(char c: s1){
            balance[c - 'a'] += 1;
        }

        for(int i = 0; i < N2; ++i){
            balance[s2[i] - 'a'] -= 1;
            if(i >= N1){
                balance[s2[i - N1] - 'a'] += 1;
            }
            if(i >= N1 - 1 && count(balance.begin(), balance.end(), 0) == A){
                return true;
            }
        }

        return false;
    }
};