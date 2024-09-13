class Solution {
public:
    int countKeyChanges(string s) {
        for(char& c: s){
            c = tolower(c);
        }
        s.resize(unique(s.begin(), s.end()) - s.begin());
        return (int)s.length() - 1;
    }
};