class Solution {
public:
    string makeFancyString(string s) {
        string res;
        for(char c: s){
            int resLen = res.length();
            if(resLen >= 2 && res[resLen - 2] == c && res[resLen - 1] == c){
                // ignore c
            }else{
                res.push_back(c);
            }
        }
        return res;
    }
};