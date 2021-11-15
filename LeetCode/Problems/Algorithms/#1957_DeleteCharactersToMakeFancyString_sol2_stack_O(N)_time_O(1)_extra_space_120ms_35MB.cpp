class Solution {
public:
    string makeFancyString(string s) {
        const int N = s.length();
        int i = 0;
        for(int j = 0; j < N; ++j){
            if(i >= 2 && s[i - 2] == s[j] && s[i - 1] == s[j]){
                continue;
            }else{
                s[i] = s[j];
                ++i;
            }
        }
        s.resize(i);
        return s;
    }
};