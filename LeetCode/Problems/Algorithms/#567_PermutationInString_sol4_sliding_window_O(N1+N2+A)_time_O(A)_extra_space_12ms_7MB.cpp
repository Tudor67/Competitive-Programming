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

        int matches = A;
        for(char c = FIRST_CHAR; c < FIRST_CHAR + A; ++c){
            if(count1[c - FIRST_CHAR] > 0){
                matches -= 1;
            }
        }

        vector<int> count2(A);
        for(int i = 0; i < N2; ++i){
            matches -= (int)(count1[s2[i] - FIRST_CHAR] == count2[s2[i] - FIRST_CHAR]);
            count2[s2[i] - FIRST_CHAR] += 1;
            matches += (int)(count1[s2[i] - FIRST_CHAR] == count2[s2[i] - FIRST_CHAR]);
            if(i >= N1){
                matches -= (int)(count1[s2[i - N1] - FIRST_CHAR] == count2[s2[i - N1] - FIRST_CHAR]);
                count2[s2[i - N1] - FIRST_CHAR] -= 1;
                matches += (int)(count1[s2[i - N1] - FIRST_CHAR] == count2[s2[i - N1] - FIRST_CHAR]);
            }
            if(matches == A){
                return true;
            }
        }

        return false;
    }
};