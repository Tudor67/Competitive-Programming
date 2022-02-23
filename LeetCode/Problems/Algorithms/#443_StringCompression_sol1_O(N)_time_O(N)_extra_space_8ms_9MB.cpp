class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        
        int count = 0;
        for(char c: chars){
            if(s.empty() || s.back() != c){
                if(count >= 2){
                    s += to_string(count);
                }
                s += c;
                count = 1;
            }else{
                count += 1;
            }
        }
        
        if(count >= 2){
            s += to_string(count);
        }
        
        for(int i = 0; i < (int)s.length(); ++i){
            chars[i] = s[i];
        }
        
        return s.length();
    }
};