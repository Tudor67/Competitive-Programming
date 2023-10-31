class Solution {
public:
    int minLength(string s) {
        const int N = s.length();

        int i = 0;
        for(int j = 1; j < N; ++j){
            if((i >= 0 && s[i] == 'A' && s[j] == 'B') ||
               (i >= 0 && s[i] == 'C' && s[j] == 'D')){
                i -= 1;
            }else{
                i += 1;
                s[i] = s[j];
            }
        }

        return (i + 1);
    }
};