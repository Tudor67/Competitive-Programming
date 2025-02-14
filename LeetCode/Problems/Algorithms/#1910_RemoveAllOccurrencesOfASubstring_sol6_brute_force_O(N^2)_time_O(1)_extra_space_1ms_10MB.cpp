class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            size_t pos = s.find(part);
            if(pos != string::npos){
                s.erase(pos, part.length());
            }else{
                return s;
            }
        }
        return "";
    }
};