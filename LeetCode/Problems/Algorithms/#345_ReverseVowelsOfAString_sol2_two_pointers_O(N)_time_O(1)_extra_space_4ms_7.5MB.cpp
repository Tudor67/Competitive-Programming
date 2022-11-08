class Solution {
private:
    bool isVowel(char c){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
public:
    string reverseVowels(string s) {
        const int N = s.length();
        
        int l = 0;
        int r = N - 1;
        while(l < r){
            if(isVowel(s[l]) && isVowel(s[r])){
                swap(s[l], s[r]);
                l += 1;
                r -= 1;
            }else{
                if(!isVowel(s[l])){
                    l += 1;
                }
                if(!isVowel(s[r])){
                    r -= 1;
                }
            }
        }
        
        return s;
    }
};