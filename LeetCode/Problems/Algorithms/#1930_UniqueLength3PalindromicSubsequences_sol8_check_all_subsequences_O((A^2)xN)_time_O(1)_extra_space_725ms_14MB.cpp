class Solution {
private:
    bool isSubseq(string& subseq, string& s){
        int i = 0;
        for(char c: s){
            if(i < (int)subseq.length() && subseq[i] == c){
                i += 1;
            }
            if(i == (int)subseq.length()){
                return true;
            }
        }
        return false;
    }

public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        for(char c1 = 'a'; c1 <= 'z'; ++c1){
            for(char c2 = 'a'; c2 <= 'z'; ++c2){
                string subseq = string(1, c1) + string(1, c2) + string(1, c1);
                if(isSubseq(subseq, s)){
                    res += 1;
                }
            }
        }
        return res;
    }
};