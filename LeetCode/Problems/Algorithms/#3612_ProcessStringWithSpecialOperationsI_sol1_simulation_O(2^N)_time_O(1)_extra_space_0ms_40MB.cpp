class Solution {
public:
    string processStr(string s) {
        const int N = s.length();

        string res;
        for(char c: s){
            if(c == '*'){
                if(!res.empty()){
                    res.pop_back();
                }
            }else if(c == '#'){
                res += res;
            }else if(c == '%'){
                reverse(res.begin(), res.end());
            }else{
                res += c;
            }
        }

        return res;
    }
};