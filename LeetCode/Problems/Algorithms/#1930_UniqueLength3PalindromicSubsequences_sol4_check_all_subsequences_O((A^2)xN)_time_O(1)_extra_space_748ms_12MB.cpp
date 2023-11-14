class Solution {
private:
    bool isSubsequence(string& subSeq, string& s){
        int i = 0;
        for(char c: s){
            if(i < (int)subSeq.length() && subSeq[i] == c){
                i += 1;
            }
            if(i == (int)subSeq.length()){
                return true;
            }
        }
        return false;
    }

public:
    int countPalindromicSubsequence(string s) {
        const int N = s.length();

        int res = 0;
        string subSeq(3, '.');
        for(char c1 = 'a'; c1 <= 'z'; ++c1){
            for(char c2 = 'a'; c2 <= 'z'; ++c2){
                subSeq[0] = c1;
                subSeq[1] = c2;
                subSeq[2] = c1;
                if(isSubsequence(subSeq, s)){
                    res += 1;
                }
            }
        }

        return res;
    }
};