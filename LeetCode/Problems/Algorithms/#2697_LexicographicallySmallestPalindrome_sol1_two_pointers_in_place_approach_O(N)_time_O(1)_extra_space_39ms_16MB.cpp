class Solution {
public:
    string makeSmallestPalindrome(string s) {
        const int N = s.length();
        
        int i = 0;
        int j = N - 1;
        while(i < j){
            if(s[i] < s[j]){
                s[j] = s[i];
            }else if(s[i] > s[j]){
                s[i] = s[j];
            }
            
            i += 1;
            j -= 1;
        }
        
        return s;
    }
};