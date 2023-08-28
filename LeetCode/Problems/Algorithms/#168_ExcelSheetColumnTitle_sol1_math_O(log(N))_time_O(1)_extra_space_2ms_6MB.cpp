class Solution {
public:
    string convertToTitle(int columnNumber) {
        int length = 1;
        long long pow26 = 26;
        while(pow26 < columnNumber){
            columnNumber -= pow26;
            pow26 *= 26;
            length += 1;
        }

        columnNumber -= 1;
        
        string res(length, 'A');
        for(int i = 0; i < length; ++i){
            pow26 /= 26;
            res[i] = char('A' + (columnNumber / pow26) % 26);
        }

        return res;
    }
};