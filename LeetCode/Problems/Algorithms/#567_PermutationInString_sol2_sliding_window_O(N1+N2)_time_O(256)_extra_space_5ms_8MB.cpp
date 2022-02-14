class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int N1 = s1.length();
        const int N2 = s2.length();
        
        vector<int> count1(128);
        for(char c: s1){
            count1[c] += 1;
        }
        
        int uniqueChars = 0;
        for(char c = 'a'; c <= 'z'; ++c){
            if(count1[c] > 0){
                uniqueChars += 1;
            }
        }
        
        int matches = 0;
        vector<int> count2(128);
        for(int i = 0; i < N2; ++i){
            count2[s2[i]] += 1;
            matches += (int)(count1[s2[i]] == count2[s2[i]]);
            if(i >= N1){
                matches -= (int)(count1[s2[i - N1]] == count2[s2[i - N1]]);
                count2[s2[i - N1]] -= 1;
            }
            if(i >= N1 - 1 && matches == uniqueChars){
                return true;
            }
        }
        
        return false;
    }
};