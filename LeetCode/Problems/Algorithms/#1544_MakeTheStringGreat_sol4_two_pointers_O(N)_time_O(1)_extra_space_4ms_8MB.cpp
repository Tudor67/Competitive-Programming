class Solution {
public:
    string makeGood(string s) {
        const int N = s.length();

        int i = -1;
        for(int j = 0; j < N; ++j){
            if(i >= 0 && tolower(s[i]) == tolower(s[j]) && s[i] != s[j]){
                i -= 1;
            }else{
                i += 1;
                s[i] = s[j];
            }
        }

        s.resize(i + 1);

        return s;
    }
};