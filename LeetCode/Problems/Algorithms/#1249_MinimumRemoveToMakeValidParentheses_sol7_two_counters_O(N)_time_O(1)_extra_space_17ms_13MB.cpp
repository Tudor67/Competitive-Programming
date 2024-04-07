class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int N = s.length();

        string res;
        int prefOpen = 0;
        int suffClosed = count(s.begin(), s.end(), ')');

        for(char c: s){
            if(c == '('){
                if(prefOpen + 1 <= suffClosed){
                    prefOpen += 1;
                    res += c;
                }
            }else if(c == ')'){
                if(prefOpen >= 1){
                    res += c;
                    prefOpen -= 1;
                }
                suffClosed -= 1;
            }else{
                res += c;
            }
        }

        return res;
    }
};