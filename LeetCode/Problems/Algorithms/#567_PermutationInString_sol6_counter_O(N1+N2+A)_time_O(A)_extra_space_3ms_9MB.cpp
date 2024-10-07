class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int N1 = s1.length();
        const int N2 = s2.length();
        const int A = 26;

        vector<int> balance(A);
        int balancedChars = A;
        for(char c: s1){
            balancedChars -= (int)(balance[c - 'a'] == 0);
            balance[c - 'a'] += 1;
        }

        for(int i = 0; i < N2; ++i){
            balancedChars -= (int)(balance[s2[i] - 'a'] == 0);
            balance[s2[i] - 'a'] -= 1;
            balancedChars += (int)(balance[s2[i] - 'a'] == 0);
            if(i >= N1){
                balancedChars -= (int)(balance[s2[i - N1] - 'a'] == 0);
                balance[s2[i - N1] - 'a'] += 1;
                balancedChars += (int)(balance[s2[i - N1] - 'a'] == 0);
            }
            if(balancedChars == A){
                return true;
            }
        }

        return false;
    }
};