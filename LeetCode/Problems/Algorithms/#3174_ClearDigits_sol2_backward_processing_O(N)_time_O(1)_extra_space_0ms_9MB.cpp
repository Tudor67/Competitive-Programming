class Solution {
public:
    string clearDigits(string s) {
        const int N = s.length();

        string res;
        int digits = 0;
        for(int i = N - 1; i >= 0; --i){
            if(isdigit(s[i])){
                digits += 1;
            }else if(digits >= 1){
                digits -= 1;
            }else{
                res.push_back(s[i]);
            }
        }

        reverse(res.begin(), res.end());
        
        return res;
    }
};