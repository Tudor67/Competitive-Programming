class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int N1 = s1.length();
        const int N2 = s2.length();
        const int A = 26;
        const int FIRST_CHAR = 'a';

        vector<int> count1(A);
        for(char c: s1){
            count1[c - FIRST_CHAR] += 1;
        }

        vector<int> count2(A);
        for(int i = 0; i < N2; ++i){
            count2[s2[i] - FIRST_CHAR] += 1;
            if(i >= N1){
                count2[s2[i - N1] - FIRST_CHAR] -= 1;
            }
            if(count1 == count2){
                return true;
            }
        }

        return false;
    }
};