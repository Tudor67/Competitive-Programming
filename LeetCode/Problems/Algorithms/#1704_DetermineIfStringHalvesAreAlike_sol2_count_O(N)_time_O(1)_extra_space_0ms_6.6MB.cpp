class Solution {
private:
    bool isVowel(char c){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
public:
    bool halvesAreAlike(string s) {
        const int N = s.length();
        
        // count[0]: number of vowels in the 1st half of s
        // count[1]: number of vowels in the 2nd half of s
        vector<int> count(2);
        for(int i = 0; i < N; ++i){
            if(isVowel(s[i])){
                count[i / (N / 2)] += 1;
            }
        }
        
        return (count[0] == count[1]);
    }
};