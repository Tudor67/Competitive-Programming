class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        res.reserve(s.length() + spaces.size());

        int j = 0;
        for(int i = 0; i < (int)s.length(); ++i){
            if(j < (int)spaces.size() && i == spaces[j]){
                res += ' ';
                j += 1;
            }
            res += s[i];
        }

        return res;
    }
};