class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        res.reserve(s.length() + spaces.size());

        int j = (int)spaces.size() - 1;
        for(int i = (int)s.length() - 1; i >= 0; --i){
            res += s[i];
            if(j >= 0 && i == spaces[j]){
                res += ' ';
                j -= 1;
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};