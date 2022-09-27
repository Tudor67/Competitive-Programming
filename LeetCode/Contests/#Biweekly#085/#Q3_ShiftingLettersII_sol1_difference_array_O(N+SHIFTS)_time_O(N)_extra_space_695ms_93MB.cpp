class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const int N = s.length();
        const int A = 26;
        
        vector<int> d(N + 1);
        for(const vector<int>& SHIFT: shifts){
            int l = SHIFT[0];
            int r = SHIFT[1];
            int dir = (SHIFT[2] == 0 ? -1 : 1);
            d[l] = (d[l] + dir + A) % A;
            d[r + 1] = (d[r + 1] - dir + A) % A;
        }
        
        int shift = 0;
        for(int i = 0; i < N; ++i){
            shift = (shift + d[i]) % A;
            if(s[i] + shift > 'z'){
                s[i] = 'a' + (s[i] + shift - 'z' - 1);
            }else{
                s[i] = s[i] + shift;
            }
        }
        
        return s;
    }
};