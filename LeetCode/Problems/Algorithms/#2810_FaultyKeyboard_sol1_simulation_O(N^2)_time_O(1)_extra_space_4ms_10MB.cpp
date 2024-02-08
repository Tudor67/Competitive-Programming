class Solution {
public:
    string finalString(string s) {
        const int N = s.length();
        
        string res;
        for(char c: s){
            if(c == 'i'){
                reverse(res.begin(), res.end());
            }else{
                res += c;
            }
        }
        
        return res;
    }
};