class Solution {
public:
    int minimumLength(string s) {
        const int N = s.length();
        
        int i = 0;
        int j = N - 1;
        while(i < j && s[i] == s[j]){
            char target = s[i];
            while(i <= j && s[i] == target){
                i += 1;
            }
            while(i <= j && s[j] == target){
                j -= 1;
            }
        }
        
        return (j - i + 1);
    }
};