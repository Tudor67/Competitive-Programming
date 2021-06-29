class Solution {
public:
    string removeDuplicates(string s) {
        const int N = s.length();
        int i = -1;
        for(int j = 0; j < N; ++j){
            if(i == -1 || s[i] != s[j]){
                i += 1;
                s[i] = s[j];
            }else{
                i -= 1;
            }
        }
        s.resize(i + 1);
        return s;
    }
};