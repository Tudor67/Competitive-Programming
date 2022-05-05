class Solution {
public:
    int solve(string& s) {
        const int N = s.length();
        
        if(N <= 2){
            return 0;
        }
        
        if(s[0] == s[N - 1]){
            s.erase(s.begin());
            s.pop_back();
            return solve(s);
        }
        
        int pos1 = find(s.begin() + 1, s.end(), s[N - 1]) - s.begin();
        int pos2 = N - 1 - (find(s.rbegin() + 1, s.rend(), s[0]) - s.rbegin());
        int moves1 = pos1;
        int moves2 = N - 1 - pos2;
        
        if(moves1 <= moves2){
            s.erase(s.begin() + pos1);
            s.pop_back();
            return moves1 + solve(s);
        }else{
            s.erase(s.begin() + pos2);
            s.erase(s.begin());
            return moves2 + solve(s);
        }
    }
    
public:
    int minMovesToMakePalindrome(string s) {
        return solve(s);
    }
};