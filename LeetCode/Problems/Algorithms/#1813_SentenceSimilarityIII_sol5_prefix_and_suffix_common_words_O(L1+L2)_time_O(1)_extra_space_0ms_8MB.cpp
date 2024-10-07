class Solution {
private:
    int getNextSpacePos(const string& S, int i){
        const int LEN = S.length();
        while(i < LEN && S[i] != ' '){
            i += 1;
        }
        return i;
    }

    int getPrevSpacePos(const string& S, int i){
        while(i >= 0 && S[i] != ' '){
            i -= 1;
        }
        return i;
    }

public:
    bool areSentencesSimilar(string s1, string s2) {
        const int LEN1 = s1.length();
        const int LEN2 = s2.length();
        const int N1 = 1 + count(s1.begin(), s1.end(), ' ');
        const int N2 = 1 + count(s2.begin(), s2.end(), ' ');

        int maxPrefixCommonWords = 0;
        int l1 = 0;
        int l2 = 0;
        while(l1 < LEN1 && l2 < LEN2){
            int r1 = getNextSpacePos(s1, l1);
            int r2 = getNextSpacePos(s2, l2);
            if(s1.compare(l1, r1 - l1, s2, l2, r2 - l2) == 0){
                maxPrefixCommonWords += 1;
                l1 = r1 + 1;
                l2 = r2 + 1;
            }else{
                break;
            }
        }

        int maxSuffixCommonWords = 0;
        int r1 = LEN1 - 1;
        int r2 = LEN2 - 1;
        while(r1 >= 0 && r2 >= 0){
            int l1 = getPrevSpacePos(s1, r1);
            int l2 = getPrevSpacePos(s2, r2);
            if(s1.compare(l1 + 1, r1 - l1, s2, l2 + 1, r2 - l2) == 0){
                maxSuffixCommonWords += 1;
                r1 = l1 - 1;
                r2 = l2 - 1;
            }else{
                break;
            }
        }

        return (maxPrefixCommonWords + maxSuffixCommonWords >= min(N1, N2));
    }
};