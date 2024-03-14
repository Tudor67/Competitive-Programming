class Solution {
public:
    string customSortString(string order, string s) {
        const int N = s.length();
        const int A = 26;

        int index = -1;
        vector<int> charToIndex(A, -1);
        for(char c: order){
            index += 1;
            charToIndex[c - 'a'] = index;
        }

        for(char c: s){
            if(charToIndex[c - 'a'] == -1){
                index += 1;
                charToIndex[c - 'a'] = index;
            }
        }

        sort(s.begin(), s.end(),
             [&](char lhs, char rhs){
                 return (charToIndex[lhs - 'a'] < charToIndex[rhs - 'a']);
             });

        return s;
    }
};