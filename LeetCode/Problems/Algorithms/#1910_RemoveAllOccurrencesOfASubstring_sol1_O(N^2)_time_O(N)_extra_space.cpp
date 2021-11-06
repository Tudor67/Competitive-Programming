class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            int pos = s.find(part);
            if(pos == string::npos){
                break;
            }else{
                s = s.substr(0, pos) + s.substr(pos + part.length());
            }
        }
        return s;
    }
};