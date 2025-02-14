class Solution {
public:
    string removeOccurrences(string s, string part) {
        for(size_t pos = s.find(part); pos != string::npos; pos = s.find(part)){
            s.erase(pos, part.length());
        }
        return s;
    }
};