class Solution {
public:
    string removeStars(string s) {
        const int N = s.length();

        int i = -1;
        for(char c: s){
            if(c == '*'){
                i -= 1;
            }else{
                i += 1;
                s[i] = c;
            }
        }

        s.resize(i + 1);

        return s;
    }
};