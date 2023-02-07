class Solution {
public:
    string convert(string s, int numRows) {
        const int N = s.length();

        if(numRows == 1){
            return s;
        }

        string res;
        vector<int> diffs = {2 * numRows - 2, 0};

        for(int startPos = 0; startPos < numRows; ++startPos){
            int prevPos = -1;
            int pos = startPos;
            int diffsIndex = 0;
            while(pos < N){
                if(prevPos != pos){
                    res += s[pos];
                    prevPos = pos;
                }
                pos += diffs[diffsIndex];
                diffsIndex = (diffsIndex + 1) % 2;
            }

            diffs[0] -= 2;
            diffs[1] += 2;
        }

        return res;
    }
};