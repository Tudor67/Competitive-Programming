class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        const int N = s.length();

        if(s.length() != words.size()){
            return false;
        }

        for(int i = 0; i < N; ++i){
            if(s[i] != words[i][0]){
                return false;
            }
        }

        return true;
    }
};