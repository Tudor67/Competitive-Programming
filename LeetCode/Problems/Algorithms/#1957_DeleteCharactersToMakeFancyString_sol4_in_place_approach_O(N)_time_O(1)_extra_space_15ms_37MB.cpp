class Solution {
public:
    string makeFancyString(string s) {
        int size = 0;
        for(int i = 0; i < (int)s.length(); ++i){
            if(size >= 2 && s[size - 2] == s[i] && s[size - 1] == s[i]){
                continue;
            }else{
                s[size] = s[i];
                size += 1;
            }
        }

        s.resize(size);

        return s;
    }
};