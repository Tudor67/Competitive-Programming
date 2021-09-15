class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        const int N = shifts.size();
        int suffixShifts = 0;
        for(int i = N - 1; i >= 0; --i){
            suffixShifts += shifts[i];
            suffixShifts %= 26;
            s[i] = 'a' + (s[i] - 'a' + suffixShifts) % 26;
        }
        return s;
    }
};