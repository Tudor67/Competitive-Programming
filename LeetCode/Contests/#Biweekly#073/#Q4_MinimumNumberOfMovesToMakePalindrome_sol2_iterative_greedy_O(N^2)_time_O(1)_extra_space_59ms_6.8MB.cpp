class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int minMoves = 0;
        
        while((int)s.length() > 2){
            int n = s.length();
            if(s[0] == s[n - 1]){
                s.erase(s.begin());
                s.pop_back();
            }else{
                int pos1 = find(s.begin() + 1, s.end(), s[n - 1]) - s.begin();
                int pos2 = n - 1 - (find(s.rbegin() + 1, s.rend(), s[0]) - s.rbegin());
                int moves1 = pos1;
                int moves2 = n - 1 - pos2;

                if(moves1 <= moves2){
                    s.erase(s.begin() + pos1);
                    s.pop_back();
                    minMoves += moves1;
                }else{
                    s.erase(s.begin() + pos2);
                    s.erase(s.begin());
                    minMoves += moves2;
                }
            }
        }
        
        return minMoves;
    }
};