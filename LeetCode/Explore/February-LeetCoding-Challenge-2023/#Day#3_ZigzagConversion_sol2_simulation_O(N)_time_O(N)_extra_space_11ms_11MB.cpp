class Solution {
public:
    string convert(string s, int numRows) {
        const int N = s.length();

        if(numRows == 1){
            return s;
        }

        vector<string> rows(numRows);
        int i = -1;
        int dir = 1;
        for(char c: s){
            i += dir;
            if(i < 0 || i >= numRows){
                dir *= -1;
                i += 2 * dir;
            }
            rows[i] += c;
        }

        string res;
        for(int i = 0; i < numRows; ++i){
            res += rows[i];
        }

        return res;
    }
};