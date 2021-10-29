class Solution {
public:
    string frequencySort(string s) {
        const int N = s.length();
        const int A = 126;
        
        vector<int> charCount(A, 0);
        for(char c: s){
            charCount[c] += 1;
        }
        
        sort(s.begin(), s.end(),
             [&](const char& LHS, const char& RHS) {
                 return (charCount[LHS] > charCount[RHS] || (charCount[LHS] == charCount[RHS] && LHS > RHS));
        });
        
        return s;
    }
};